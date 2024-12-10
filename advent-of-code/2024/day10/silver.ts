import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

let grid = [];
const lines = text.split("\n");
for (let line of lines) {
  grid.push(line.split(""));
}

let mx = [-1, 0, 1, 0];
let my = [0, -1, 0, 1];

for (let i = 0; i < grid.length; i++) {
  for (let j = 0; j < grid[i].length; j++) {
    if (grid[i][j] === "0") {
      let q = [[i, j]];
      const visited = new Set<string>();
      while (q.length) {
        const [x, y] = q.pop()!;
        visited.add(`${x},${y}`);
        if (grid[x][y] === "9") {
          target++;
        }
        for (let [dx, dy] of [[-1, 0], [0, -1], [1, 0], [0, 1]]) {
          const nx = x + dx;
          const ny = y + dy;
          if (visited.has(`${nx},${ny}`)) {
            continue;
          }
          if (nx < 0 || nx >= grid.length || ny < 0 || ny >= grid[i].length) {
            continue;
          }
          if (Number(grid[nx][ny]) === Number(grid[x][y]) + 1) {
            q.push([nx, ny]);
          }
        }
      }
    }
  }
}

console.log(target);
