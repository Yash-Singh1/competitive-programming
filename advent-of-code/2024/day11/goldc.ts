// TODO: for fun bitwise to make it faster

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
    let realnum = str.length;
    let base2bit = Math.log2((realnum ^ (realnum - 1)) + 1) - 1;
    let basenum = realnum >>> base2bit;
    console.log(basenum, base2bit, realnum);
    let base2 = base2bit;
    for (let i = 0; i < str.length; i += basenum) {
      if (str.charCodeAt(i) === 48) {
        base2 = Math.min(base2, Math.log2((i ^ (i - 1)) + 1));
      }
    }
    let digits = str.length >> base2;
    let digits2 = str.length;
    let base22 = 0;
    whileLoop: while (digits2 % 2 === 0 && level + base22 < MAX_LEVELS) {
      digits2 /= 2;
      for (
        let i = digits2 === str.length ? 0 : digits2;
        i < str.length;
        i += 2 * digits2
      ) {
        if (str.charCodeAt(i) === 48) {
          base22++;
          break whileLoop;
        }
      }
      base22++;
    }
    if (digits !== digits2 || base2 !== base22) {
      console.error(digits, digits2, base2, base22, num, level);
      throw new Error("Error");
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
