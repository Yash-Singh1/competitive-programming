import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

lines.forEach((line) => {
  const cache = new Map<string, number>();
  let [pattern, need] = line.split(" ");
  let originalpattern = pattern;
  let originalneed = need;
  for (let i = 0; i < 8; ++i) {
    need = need + "," + originalneed;
    pattern = pattern + "?" + originalpattern;
  }
  let needed = need.split(",").map(Number);

  function calc(pos: number, neededpos: number) {
    const key = `${pos},${neededpos}`;
    if (cache.has(key)) {
      return cache.get(key)!;
    }

    if (neededpos === needed.length) {
      if (pattern.slice(pos).includes("#")) {
        return 0;
      } else {
        return 1;
      }
    }

    let nextneeded = pattern.slice(pos, pos + needed[neededpos]);
    let tot = 0;
    if (nextneeded.length === needed[neededpos]) {
      if (!nextneeded.includes(".")) {
        let nextpos = pos + needed[neededpos];
        if (nextpos === pattern.length) {
          tot += calc(nextpos, neededpos + 1);
        } else if (pattern[nextpos] !== "#") {
          tot += calc(nextpos + 1, neededpos + 1);
        }
      }
    } else {
      return 0;
    }

    if (pattern[pos] !== "#") {
      tot += calc(pos + 1, neededpos);
    }

    cache.set(key, tot);

    return tot;
  }

  ans += calc(0, 0);
});

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
