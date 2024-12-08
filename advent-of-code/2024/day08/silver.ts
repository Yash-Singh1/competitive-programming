import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

const grid = text.split("\n").map((line) => line.split(""));

const n = grid.length;
const m = grid[0].length;

const mp: { [key: string]: [number, number][] } = {};

for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (grid[i][j] !== ".") {
      if (mp[grid[i][j]] === undefined) {
        mp[grid[i][j]] = [];
      }
      mp[grid[i][j]].push([i, j]);
    }
  }
}

const antinodes = new Set<string>();

for (const [freq, poses] of Object.entries(mp)) {
  for (let i = 0; i < poses.length; i++) {
    for (let j = i + 1; j < poses.length; j++) {
      const [x1, y1] = poses[i];
      const [x2, y2] = poses[j];
      const dx = x2 - x1;
      const dy = y2 - y1;
      if (dx === 0 || dy === 0) {
        continue;
      }
      const newx1 = x1 - dx;
      const newy1 = y1 - dy;
      const newx2 = x2 + dx;
      const newy2 = y2 + dy;
      if (newx1 >= 0 && newx1 < n && newy1 >= 0 && newy1 < m) {
        antinodes.add([newx1, newy1].join(','));
      }
      if (newx2 >= 0 && newx2 < n && newy2 >= 0 && newy2 < m) {
        antinodes.add([newx2, newy2].join(','));
      }
    }
  }
}

console.log(antinodes.size);
