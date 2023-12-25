import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let sum = 0;

const seeds = lines[0]
  .trim()
  .split(": ")[1]
  .trim()
  .split(/\s+/)
  .filter(Boolean)
  .map((x) => Number(x.trim()));
const maps = trimmed
  .split(DELIM + DELIM)
  .slice(1)
  .map((x) => x.trim())
  .filter(Boolean)
  .map((map) => {
    const header = map.split(DELIM)[0];
    const content = map
      .split(DELIM)
      .slice(1)
      .map((line) => line.trim())
      .filter(Boolean)
      .map((line) =>
        line
          .split(/\s+/)
          .filter(Boolean)
          .map((x) => Number(x.trim()))
      )
      .sort();
    return content;
  });

let mn = Infinity;

console.log(seeds);
console.log(maps);

let frseeds: number[] = [];
seeds.forEach((x, i) => {
  if (i % 2) return;
  frseeds.push(x);
  frseeds.push(seeds[i + 1] + x + 1);
});

let i = 0;
const memo = new Map<number, number>();
// const mapAllTheWay = new Map<string, number>();

function evalRev(seed: number, mapi: number) {
  if (memo.has(seed)) return memo.get(seed)!;
  let orig = seed;
  for (let i = mapi; i >= 0; --i) {
    const map = maps[i];
    for (const line of map) {
      if (line[0] <= seed && line[0] + line[2] > seed) {
        seed = line[1] + (seed - line[0]);
        break;
      }
    }
  }
  memo.set(orig, seed);
  return seed;
}
const intersectRev = [
  ...maps
    .slice(1)
    .flatMap((mp, idx) =>
      mp.flatMap((x) => [x[1], x[1] + x[2], x[1] + x[2] + 1, x[0], x[0] + x[2] + 1 ,x[0] + x[2]]).map((x) => evalRev(x, idx))
    ),
];
intersectRev.sort(function(a, b){return a-b});
const skipPoints = [...intersectRev, ...frseeds];
skipPoints.sort(function(a, b){return a-b});
console.log(intersectRev);

for (let seedori of seeds) {
  if (i % 2) {
    ++i;
    continue;
  }
  for (
    let seedout = seedori;
    seedout < seedori + seeds[i + 1];
    seedout = skipPoints.find((x) => x > seedout)!
  ) {
    console.log(seedout);
    let seed = seedout;
    // if (memo.has(seed)) continue;
    // const mapvals = [];
    // mapvals.push(seed);
    // let rr2 = 1;
    // let dontpush = false;
    for (const map of maps) {
      // if (mapAllTheWay.has([seed, rr2].join(","))) {
      //   seed = mapAllTheWay.get([seed, rr2].join(","))!;
      //   dontpush = true;
      //   continue;
      // }
      for (const line of map) {
        if (line[1] <= seed && line[1] + line[2] > seed) {
          seed = line[0] + (seed - line[1]);
          break;
        }
      }
      // ++rr2;
      // mapvals.push(seed);
    }
    // if (dontpush) continue;
    // let rr = 1;
    // for (const mapval of mapvals) {
    //   mapAllTheWay.set([mapval, rr].join(","), mapvals[mapvals.length - 1]);
    //   ++rr;
    // }
    console.log(i / 2, seed);
    mn = Math.min(mn, seed);
  }
  ++i;
}

sum = mn;

console.log(sum);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + sum + "\n"
);
