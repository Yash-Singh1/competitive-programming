import assert, { fail } from "node:assert";
import fs from "node:fs";
import { MaxPriorityQueue } from "@datastructures-js/priority-queue";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

let grid = lines.map((line) => line.split(""));

// let q: [number, number, number, Set<number>][] = [];

// q.push([0, 0, 1, new Set([1])]);

let dirs = [
  [0, 1],
  [0, -1],
  [1, 0],
  [-1, 0],
];

let sloped = {
  ">": 0,
  "<": 1,
  v: 2,
  "^": 3,
};

let visited = new Set<number>();

function dfs(x, y, l) {
  if (x === grid.length - 1 && y === grid[0].length - 2) {
    ans = Math.max(ans, l);
    return;
  }

  for (let [dx, dy] of dirs) {
    let nx = x + dx;
    let ny = y + dy;
    if (nx < 0 || nx >= grid.length || ny < 0 || ny >= grid[0].length) continue;
    if (grid[nx][ny] === "#") continue;
    if (visited.has(nx * 1000 + ny)) continue;
    if (
      (grid[nx][ny] in sloped &&
        (dx !== dirs[sloped[grid[nx][ny]]][0] || dy !== dirs[sloped[grid[nx][ny]]][1])) ||
      (grid[x][y] in sloped &&
        (dx !== dirs[sloped[grid[x][y]]][0] || dy !== dirs[sloped[grid[x][y]]][1]))
    )
      continue;
    visited.add(nx * 1000 + ny);
    dfs(nx, ny, l + 1);
    visited.delete(nx * 1000 + ny);
  }
}

visited.add(1);

dfs(0, 1, 0);

console.log(ans);
// fs.writeFileSync(
//   "out.txt",
//   fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
// );
