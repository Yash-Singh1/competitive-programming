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

firstList.sort();
secondList.sort();

let sum = 0;

for (let i = 0; i < firstList.length; i++) {
  sum += Math.abs(firstList[i][0] - secondList[i][0]);
  // console.log(sum);
}

console.log(sum);
