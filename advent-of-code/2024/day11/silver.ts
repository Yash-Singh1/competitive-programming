import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

let nums = text.split(" ").map((n) => parseInt(n));

for (let i = 0; i < 25; i++) {
  let newStones = [];
  for (let j = 0; j < nums.length; j++) {
    if ((Math.floor(Math.log10(nums[j])) + 1) % 2 === 0) {
      // newStones.push(
      //   Math.floor(nums[j] / (10 ** (Math.floor(Math.log10(nums[j])) + 1) / 2))
      // );
      // newStones.push(
      //   nums[j] -
      //     (10 ** (Math.floor(Math.log10(nums[j])) + 1) / 2) *
      //       newStones[newStones.length - 1]
      // );
      newStones.push(
        Number(nums[j].toString().slice(0, nums[j].toString().length / 2))
      );
      newStones.push(
        Number(nums[j].toString().slice(nums[j].toString().length / 2))
      );
    } else if (nums[j] === 0) {
      newStones.push(1);
    } else {
      newStones.push(nums[j] * 2024);
    }
  }
  nums = newStones;
}

console.log(nums.length);
