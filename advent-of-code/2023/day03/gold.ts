import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const lines = input.split(DELIM);
const trimmed = input.trim();

let sum = 0;

let grid = trimmed.split(DELIM);

const mx = [1, -1, 0, 0, 1, 1, -1, -1];
const my = [0, 0, 1, -1, 1, -1, 1, -1];

for (let i = 0; i < grid.length; ++i) {
  let numStart = -2;
  let numEnd = -2;
  for (let j = 0; j < grid[i].length; ++j) {
    if (grid[i][j] === "*") {
      let detect = [];
      for (let k = 0; k < 8; ++k) {
        if (
          i + mx[k] < 0 ||
          i + mx[k] >= grid.length ||
          j + my[k] < 0 ||
          j + my[k] >= grid[i].length
        )
          continue;
        if (!isNaN(Number(grid[i+mx[k]][j+my[k]]))) {
          detect.push([i+mx[k], j+my[k]]);
        }
      }
      const numsaround = new Set<string>();
      for (let k = 0; k < detect.length; ++k) {
        for (let l = detect[k][1]; l >= 0; --l) {
          if (!isNaN(Number(grid[detect[k][0]][l]))) {
            numStart = l;
          } else {
            break;
          }
        }
        for (let l = detect[k][1]; l < grid[detect[k][0]].length; ++l) {
          if (!isNaN(Number(grid[detect[k][0]][l]))) {
            numEnd = l;
          } else {
            break;
          }
        }
        numsaround.add([detect[k][0], numStart, numEnd].join(","));
      }
      if (numsaround.size === 2) {
        let ans = 1;
        for (const val of numsaround.values()) {
          const [ii, start, end] = val.split(",").map(val => Number(val));
          ans *= Number(grid[ii].slice(start, end + 1));
        }
        sum += ans;
      }
    }
  }
}

console.log(sum);
