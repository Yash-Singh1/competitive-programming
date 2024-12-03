import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

let muls = text.matchAll(/(mul\((\d+),(\d+)\))|(do|don't)\(\)/g);
let active = true;
for (const mul of muls) {
  console.log(mul[4]);
  if (mul[4] === "do") {
    active = true;
  } else if (mul[4] === "don't") {
    active = false;
  } else if (active) {
    target += Number(mul[2]) * Number(mul[3]);
  }
}

console.log(target);
