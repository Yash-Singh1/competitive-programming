import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

let muls = text.matchAll(/mul\((\d+),(\d+)\)/g);
for (const mul of muls) {
  target += Number(mul[1]) * Number(mul[2]);
}

console.log(target);
