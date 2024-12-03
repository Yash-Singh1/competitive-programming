import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

let lines = text.split("\n");
for (const line of lines) {
  const nums = line.trim().split(/\s+/).map(Number);
  let safe = true;
  let increasing = nums[1] > nums[0];
  for (let i = 1; i < nums.length; i++) {
    if (
      (increasing && nums[i] < nums[i - 1]) ||
      (!increasing && nums[i - 1] < nums[i])
    ) {
      safe = false;
      break;
    }
    if (
      Math.abs(nums[i] - nums[i - 1]) < 1 ||
      Math.abs(nums[i] - nums[i - 1]) > 3
    ) {
      safe = false;
      break;
    }
  }
  if (safe) target++;
}

console.log(target);
