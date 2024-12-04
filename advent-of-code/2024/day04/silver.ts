import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

let grid = text.split("\n").map((line) => line.split(""));
let mx = [0, 0, 1, -1, 1, -1, 1, -1];
let my = [1, -1, 1, -1, 0, 0, -1, 1];
let str = "XMAS";
for (let i = 0; i < grid.length; i++) {
  for (let j = 0; j < grid[0].length; j++) {
    for (let k = 0; k < mx.length; k++) {
      let curChar = grid[i][j];
      let curI = 0;
      let curX = i;
      let curY = j;
      while (curChar === str[curI] && curI < str.length) {
        curX += mx[k];
        curY += my[k];
        curI++;
        if (
          curX >= grid.length ||
          curX < 0 ||
          curY >= grid[0].length ||
          curY < 0
        )
          break;
        curChar = grid[curX][curY];
      }
      if (curI === str.length) {
        target++;
      }
    }
  }
}

console.log(target);
