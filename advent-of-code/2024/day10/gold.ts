import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

let grid = [];
const lines = text.split("\n");
for (let line of lines) {
  grid.push(line.split(""));
}

let q = [];
for (let i = 9; i >= 0; i--) {
  let pq = q;
  q = [];
  for (let j = 0; j < grid.length; j++) {
    for (let k = 0; k < grid[j].length; k++) {
      if (Number(grid[j][k]) === i) {
        if (i === 9) q.push([j, k, 1]);
        else {
          let mx = [-1, 0, 1, 0];
          let my = [0, 1, 0, -1];
          let found = 0;
          for (let l = 0; l < 4; l++) {
            let dx = mx[l];
            let dy = my[l];
            // console.log(pq, j, k, pq.find((p) => p[0] === j + dy && p[1] === k + dx), j + dy, k + dx);
            if (
              j + dy >= 0 &&
              j + dy <= grid.length &&
              k + dx >= 0 &&
              k + dx <= grid[j].length &&
              pq.find((p) => p[0] === j + dy && p[1] === k + dx)
            ) {
              found += pq.find((p) => p[0] === j + dy && p[1] === k + dx)![2];
            }
          }
          console.log(i, j, k, found);
          q.push([j, k, found]);
        }
      }
    }
  }
  console.log(q.reduce((a, b) => a + b[2], 0));
}

console.log(target);
