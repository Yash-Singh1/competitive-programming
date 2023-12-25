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

let i = 0;
for (let seed of seeds) {
  for (const map of maps) {
    for (const line of map) {
      if (line[1] <= seed && line[1] + line[2] > seed) {
        console.log(i, seed, line)
        seed = line[0] + (seed - line[1]);
        break;
      }
    }
  }
  ++i;
  mn = Math.min(mn, seed);
}

sum = mn;

console.log(sum);
// fs.writeFileSync(
//   "out.txt",
//   fs.readFileSync("out.txt", "utf-8") + "\n" + sum + "\n"
// );
