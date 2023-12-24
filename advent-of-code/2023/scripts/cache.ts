// Purpose: Migrate the benchmark results to a new format that is easier to cache

import type { Result } from "./benchmark";
import benchmap from "./benchmap";

const hasher = new Bun.CryptoHasher("sha256");

async function cacheAllResults() {
  const benches = await Bun.file("bench.json").json<Record<string, Result>>();
  const result: Record<string, Record<string, Result>> = {};

  for (const [problem, time] of Object.entries(benches)) {
    const [day, part] = problem.split("/");
    const partText = Number(part) === 1 ? "silver" : "gold";
    const runtimeFile = `${
      benchmap.map?.[Number(day)]?.[partText] ?? partText
    }.ts`;
    hasher.update(await Bun.file(`./day${day}/${runtimeFile}`).text());
    const hash = hasher.digest("base64");
    if (result[problem] === undefined) {
      result[problem] = {};
    }
    result[problem][hash] = time;
  }

  Bun.write("benchmarks.cache.json", JSON.stringify(result, null, 2));
}

cacheAllResults();
