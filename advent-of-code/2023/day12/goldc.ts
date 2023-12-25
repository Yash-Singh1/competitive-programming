import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

lines.forEach((line) => {
  const cache = new Map<number, number>();
  let [pattern, need] = line.split(" ");
  let originalpattern = pattern;
  let originalneed = need;
  for (let i = 0; i < 4; ++i) {
    need = need + "," + originalneed;
    pattern = pattern + "?" + originalpattern;
  }
  let needed = need.split(",").map(Number);

  let mxToHash = pattern.length;
  for (let i = pattern.length - 1; i >= 0; --i) {
    if (pattern[i] === "#") break;
    --mxToHash;
  }

  let hasNoDotsTill = pattern.split("").map(() => pattern.length);
  for (let i = 0; i < pattern.length; ++i) {
    if (i && hasNoDotsTill[i - 1] > i) {
      hasNoDotsTill[i] = hasNoDotsTill[i - 1];
      continue;
    }
    for (let j = i; j < pattern.length; ++j) {
      if (pattern[j] === ".") {
        hasNoDotsTill[i] = j;
        break;
      }
    }
  }

  function calc(pos: number, neededpos: number) {
    const key = pos * pattern.length + neededpos;
    if (cache.has(key)) {
      return cache.get(key)!;
    }

    if (neededpos === needed.length) {
      if (pos < mxToHash) {
        return 0;
      } else {
        return 1;
      }
    }

    let tot = 0;
    if (pattern.length - pos >= needed[neededpos]) {
      if (hasNoDotsTill[pos] >= pos + needed[neededpos]) {
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
// fs.writeFileSync(
//   "out.txt",
//   fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
// );
