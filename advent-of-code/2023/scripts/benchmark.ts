import { spawn } from "bun";
import { readdirSync, statSync } from "fs";
import ora from "ora";
import benchmap from "./benchmap";

const DAY_REGEX = /^day(\d+)$/;

export type Result = "TLE" | "RE" | number;

const parts = ["silver", "gold"];

const hasher = new Bun.CryptoHasher("sha256");

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
  const currentBench = await Bun.file("bench.json").json<
    Record<string, Record<string, Result>>
  >();

  const final: Record<string, Result> = {};
  for (const dayDir of days) {
    const [, dayNumber] = DAY_REGEX.exec(dayDir)!;

    let overall = 0;
    for (const part of ["silver", "gold"] as const) {
      if (benchmap.skip.includes(`${dayDir}/${part}`)) {
        continue;
      }

      let results: Result[] = [];
      const partNum = parts.indexOf(part) + 1;
      const input = Bun.file(`${dayDir}/in.txt`);
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
        const process = spawn({
          cmd: [...runtimeCmd[runtime], runtimeFile, "in.txt"],
          cwd: `./${dayDir}`,
          stdin: input,
        });
        let tle = true;
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
          results.push(performance.now() - start);
          overall += performance.now() - start;
          if (i < 4) {
            spinner.text = `Running day ${dayNumber} Part ${partNum} (${
              i + 1
            }/5)`;
          }
        }
      }
      // console.log(results);
      if (!isNaN(Number(results[results.length - 1]))) {
        spinner.succeed(
          `Day ${dayNumber} Part ${partNum} average: ${Math.round(
            overall / 5
          )}ms`
        );
        final[[dayNumber, partNum].join("/")] = Math.round(overall / 5);
      } else {
        final[[dayNumber, partNum].join("/")] = results[results.length - 1];
      }
    }
  }

  const cacheResult = await cacheAllResults(final);

  await Bun.write("bench.json", JSON.stringify(cacheResult, null, 2));
}

runAll();
