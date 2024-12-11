import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0n;

let nums = text.split(" ").map((n) => BigInt(n));

// for (let i = 0; i < 25; i++) {
//   let newStones = [];
//   for (let j = 0; j < nums.length; j++) {
//     if ((Math.floor(Math.log10(nums[j])) + 1) % 2 === 0) {
//       // newStones.push(
//       //   Math.floor(nums[j] / (10 ** (Math.floor(Math.log10(nums[j])) + 1) / 2))
//       // );
//       // newStones.push(
//       //   nums[j] -
//       //     (10 ** (Math.floor(Math.log10(nums[j])) + 1) / 2) *
//       //       newStones[newStones.length - 1]
//       // );
//       newStones.push(
//         Number(nums[j].toString().slice(0, nums[j].toString().length / 2))
//       );
//       newStones.push(
//         Number(nums[j].toString().slice(nums[j].toString().length / 2))
//       );
//     } else if (nums[j] === 0) {
//       newStones.push(1);
//     } else {
//       newStones.push(nums[j] * 2024);
//     }
//   }
//   nums = newStones;
// }

const done = new Map<string, bigint>();
const MAX_LEVELS = 75;

function processNum(num: bigint, level = 0) {
  if (done.has([num, level].join(","))) {
    return done.get([num, level].join(","))!;
  }
  let ans: bigint;
  if (level === MAX_LEVELS) {
    return 1n;
  }
  if (num === 0n) {
    return processNum(1n, level + 1);
  } else if (num.toString().length % 2 === 0) {
    const str = num.toString();
    ans = processNum(BigInt(str.slice(0, str.length / 2)), level + 1) + processNum(BigInt(str.slice(str.length / 2)), level + 1);
    // let digits = str.length;
    // let base2 = 0;
    // while (digits % 2 === 0 && level + base2 < MAX_LEVELS) {
    //   digits /= 2;
    //   base2++;
    // }
    // if (base2 === 0) {
    //   console.error(num);
    // }
    // let sum = 0n;
    // for (let i = 0; i < str.length; i += digits) {
    //   sum += processNum(BigInt(str.slice(i, i + digits)), level + base2);
    // }
    // ans = sum;
  } else {
    ans = processNum(num * 2024n, level + 1);
  }
  done.set([num, level].join(","), ans);
  return ans;
}

console.log(nums.length);
for (const num of nums) {
  target += processNum(num);
}
console.log(target);
