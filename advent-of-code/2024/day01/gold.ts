import * as fs from "node:fs";

const lines = (await fs.readFileSync("./input.txt", "utf-8"))
  .trim()
  .split("\n");

const firstList: [number, number][] = lines.map((line, i) => [
  Number(line.split(" ")[0]),
  i,
]);
const secondList: [number, number][] = lines.map((line, i) => [
  Number(line.split(" ").at(-1)),
  i,
]);

const mp = new Map<number, number>();
for (const a of secondList) {
  mp.set(a[0], (mp.get(a[0]) || 0) + 1);
}

firstList.sort();
secondList.sort();

let sum = 0;

for (const num of firstList) {
  sum += (mp.get(num[0]) || 0) * num[0];
}

console.log(sum);
