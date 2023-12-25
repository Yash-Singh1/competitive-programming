import { spawn } from "bun";
import { readdirSync, statSync } from "fs";
import ora from "ora";
import benchmap from "./benchmap";
import { markdownTable } from "markdown-table";

const DAY_REGEX = /^day(\d+)$/;

export type Result = "TLE" | "RE" | number;

const parts = ["silver", "gold"];

const hasher = new Bun.CryptoHasher("sha256");

const BENCHMARK_START = "<!-- BENCHMARK_START -->";
const BENCHMARK_END = "<!-- BENCHMARK_END -->";
const tableHeaders = ["Day", "TypeScript", "Rust"];
const padLeft = Intl.NumberFormat("en-US", {
  minimumIntegerDigits: 2,
});

async function cacheAllResults(benches: Record<string, Result>) {
  const result: Record<string, Record<string, Result>> = {};

  for (const [problem, time] of Object.entries(benches)) {
    const [day, part] = problem.split("/");
    const partText = Number(part) === 1 ? "silver" : "gold";
    const runtimeFile = `${
      benchmap.map?.[Number(day)]?.[partText] ?? `${partText}.ts`
    }`;
    hasher.update(await Bun.file(`./day${day}/${runtimeFile}`).text());
    const hash = hasher.digest("base64");
    if (result[problem] === undefined) {
      result[problem] = {};
    }
    result[problem][hash] = time;
  }

  return result;
}

// From https://stackoverflow.com/a/17268489/13514657
function getColor(value: number) {
  // value from 0 to 1
  var hue = ((1 - value) * 120).toString(10);
  return [parseInt(hue), 100, 50] as const;
}

// From https://stackoverflow.com/a/44134328/13514657
function hslToHex(h, s, l) {
  l /= 100;
  const a = (s * Math.min(l, 1 - l)) / 100;
  const f = (n) => {
    const k = (n + h / 30) % 12;
    const color = l - a * Math.max(Math.min(k - 3, 9 - k, 1), -1);
    return Math.round(255 * color)
      .toString(16)
      .padStart(2, "0"); // convert to Hex and prefix "0" if needed
  };
  return `${f(0)}${f(8)}${f(4)}`;
}

const runtimeCmd = {
  node: ["node"],
  bun: ["bun", "run"],
};

async function runAll() {
  let days = readdirSync(".")
    .filter((directory) => {
      const stat = statSync(directory);
      if (!stat.isDirectory) {
        return false;
      }
      return DAY_REGEX.test(directory);
    })
    .sort();
  let currentBench: Record<string, Record<string, Result>>;
  try {
    currentBench = await Bun.file("bench.json").json<
      Record<string, Record<string, Result>>
    >();

    await Bun.write(Bun.file("bench.cache.json"), Bun.file("bench.json"));
  } catch {
    currentBench = {};
  }

  const final: Record<string, Result> = {};
  let overallTimes: [number, string][] = [];

  for (const dayDir of days) {
    const [, dayNumber] = DAY_REGEX.exec(dayDir)!;

    let overall = 0;

    for (const part of ["silver", "gold"] as const) {
      if (benchmap.skip.includes(`${dayDir}/${part}`)) {
        continue;
      }

      let results: Result[] = [];
      const partNum = parts.indexOf(part) + 1;
      const runtimeFile = `./${
        benchmap.map?.[Number(dayNumber)]?.[part] ?? `${part}.ts`
      }`;
      const hash = hasher
        .update(await Bun.file(`./${dayDir}/${runtimeFile}`).text())
        .digest("base64");

      if (
        typeof currentBench?.[`${dayNumber}/${partNum}`]?.[hash] !== "undefined"
      ) {
        final[[dayNumber, partNum].join("/")] =
          currentBench[`${dayNumber}/${partNum}`][hash];
        if (typeof currentBench[`${dayNumber}/${partNum}`][hash] === "number") {
          overallTimes.push([
            currentBench[`${dayNumber}/${partNum}`][hash] as number,
            [dayNumber, partNum].join("/"),
          ]);
        }
        ora(`Cache hit for day ${dayNumber} Part ${partNum}`).start().succeed();
        continue;
      }

      const spinner = ora(
        `Running day ${dayNumber} Part ${partNum} (1/5)`
      ).start();

      const runtime = benchmap.runtimeMap?.[Number(dayNumber)]?.[part] ?? "bun";

      let tled = 0;
      for (let i = 0; i < 5; i++) {
        const start = performance.now();
        let tle = true;
        let end;
        const process = spawn({
          cmd: [...runtimeCmd[runtime], runtimeFile, "in.txt"],
          cwd: `./${dayDir}`,
          onExit() {
            end = performance.now();
          },
        });
        for (let i = 0; i < 200; ++i) {
          if (process.killed) {
            tle = false;
            break;
          }
          await new Promise((resolve) => setTimeout(resolve, 100));
        }
        if (tle) {
          --i;
          process.kill();
          results.push("TLE");
          spinner.fail("Time Limit Exceeded");
          break;
        } else if (process.exitCode! > 0) {
          results.push("RE");
          spinner.fail("Runtime Error");
          break;
        } else {
          results.push(end - start);
          overall += results[results.length - 1] as number;
          if (i < 4) {
            spinner.text = `Running day ${dayNumber} Part ${partNum} (${
              i + 1
            }/5)`;
          }
        }
      }
      // console.log(results);
      if (!isNaN(Number(results[results.length - 1]))) {
        const millisecondsRounded = parseFloat((overall / 5).toFixed(3));
        spinner.succeed(
          `Day ${dayNumber} Part ${partNum} average: ${millisecondsRounded}ms`
        );
        final[[dayNumber, partNum].join("/")] = millisecondsRounded;
        overallTimes.push([millisecondsRounded, `${dayNumber}/${partNum}`]);
      } else {
        final[[dayNumber, partNum].join("/")] = results[results.length - 1];
      }
    }
  }

  const cacheResult = await cacheAllResults(final);

  await Bun.write("bench.json", JSON.stringify(cacheResult, null, 2));

  overallTimes.sort();

  const problemToRank = new Map<string, number>();
  for (let i = 0; i < overallTimes.length; ++i) {
    problemToRank.set(overallTimes[i][1], i);
  }

  let markdown = await Bun.file("README.md").text();
  const table = [tableHeaders];
  for (let i = 1; i <= 25; ++i) {
    const dayStr = padLeft.format(i);
    table.push([
      i.toString(),
      [
        typeof final?.[`${dayStr}/1`] === "string"
          ? final?.[`${dayStr}/1`]
          : final?.[`${dayStr}/1`]
          ? `![](https://placehold.co/10x10/${hslToHex(
              ...getColor(
                problemToRank.get(`${dayStr}/1`) / (overallTimes.length - 1)
              )
            )}/000.png?text=%5Cn)${final?.[`${dayStr}/1`]}ms`
          : "--",
        typeof final?.[`${dayStr}/2`] === "string"
          ? final?.[`${dayStr}/2`]
          : final?.[`${dayStr}/2`]
          ? `![](https://placehold.co/10x10/${hslToHex(
              ...getColor(
                problemToRank.get(`${dayStr}/2`) / (overallTimes.length - 1)
              )
            )}/000.png?text=%5Cn)${final?.[`${dayStr}/2`]}ms`
          : "--",
      ].join("/"),
      "--/--",
    ]);
  }

  markdown = markdown.replace(
    /<!--\s*BENCHMARK_START\s*-->[^]+<!--\s*BENCHMARK_END\s*-->/,
    `${BENCHMARK_START}
${markdownTable(table)}
${BENCHMARK_END}`
  );

  await Bun.write("README.md", markdown);
}

runAll();
