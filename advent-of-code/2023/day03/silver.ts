import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync("in.txt", "utf-8");
const lines = input.split(DELIM);
const trimmed = input.trim();

let sum = 0;

let grid = trimmed.split(DELIM);

const mx = [1, -1, 0, 0, 1, 1, -1, -1];
const my = [0, 0, 1, -1, 1, -1, 1, -1];

for (let i = 0; i < grid.length; ++i) {
  let numStart = -2;
  let numEnd = -2;
  let numMatch = false;
  for (let j = 0; j < grid[i].length; ++j) {
    if (!isNaN(Number(grid[i][j]))) {
      if (numStart < 0) {
        numStart = j;
        numMatch = false;
      }
      numEnd = j;
      for (let k = 0; k < 8; ++k) {
        if (
          i + mx[k] < 0 ||
          i + mx[k] >= grid.length ||
          j + my[k] < 0 ||
          j + my[k] >= grid[i].length
        )
          continue;
        if (
          grid[i + mx[k]][j + my[k]] !== "." &&
          isNaN(Number(grid[i + mx[k]][j + my[k]]))
        ) {
          numMatch = true;
        }
      }
    } else {
      if (numStart >= 0) {
        if (numMatch) {
          sum += Number(grid[i].slice(numStart, numEnd + 1));
        }
        numMatch = false;
        numStart = -1;
        numEnd = -1;
      }
    }
  }
  if (numMatch) {
    sum += Number(grid[i].slice(numStart, numEnd + 1));
  }
}

console.log(sum);
