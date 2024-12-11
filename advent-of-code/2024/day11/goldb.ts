// Fixed up base2 skips to handle the case in which a part starts with 0

import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0n;

let nums = text.split(" ").map((n) => BigInt(n));

const done = new Map<string, bigint>();
const MAX_LEVELS = 75;

function processNum(num: bigint, level = 0) {
  if (level === MAX_LEVELS) {
    return 1n;
  }
  if (done.has([num, level].join(","))) {
    return done.get([num, level].join(","))!;
  }
  let ans: bigint;
  let str;
  if (num === 0n) {
    ans = processNum(1n, level + 1);
  } else if ((str = num.toString()).length % 2 === 0) {
    let digits = str.length;
    let base2 = 0;
    whileLoop: while (digits % 2 === 0 && level + base2 < MAX_LEVELS) {
      digits /= 2;
      for (
        let i = digits === str.length ? 0 : digits;
        i < str.length;
        i += 2 * digits
      ) {
        if (str.charCodeAt(i) === 48) {
          base2++;
          break whileLoop;
        }
      }
      base2++;
    }
    let sum = 0n;
    for (let i = 0; i < str.length; i += digits) {
      sum += processNum(BigInt(str.slice(i, i + digits)), level + base2);
    }
    ans = sum;
  } else {
    ans = processNum(num * 2024n, level + 1);
  }
  done.set([num, level].join(","), ans);
  return ans;
}

for (const num of nums) {
  target += processNum(num);
}
console.log(target.toString());
