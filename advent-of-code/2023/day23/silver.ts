import assert, { fail } from "node:assert";
import fs from "node:fs";
import { MaxPriorityQueue } from "@datastructures-js/priority-queue";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

let grid = lines.map((line) => line.split(""));

let q: [number, number, number, Set<number>][] = [];
// const q = new MaxPriorityQueue<[number, number, number, Set<number>]>(
//   (a) => a[0]
// );

q.push([0, 0, 1, new Set([1])]);

// for (let i = 0; i < grid.length; ++i) {
//   for (let j = 0; j < grid[i].length; ++j) {
//     q.push([0, i, j, new Set([i * 1000 + j])]);
//   }
// }

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

// const visited = new Set<string>();

while (q.length) {
  let [l, x, y, _visited] = q.shift()!;

  // if (visited.has([l, x, y, [..._visited].join(":")].join(","))) {
  //   continue;
  // }
  // console.log(l);

  // console.log("\n\n");
  // if (l > ans) {
  //   for (let i = 0; i < grid.length; ++i) {
  //     for (let j = 0; j < grid[i].length; ++j) {
  //       process.stdout.write(_visited.has(i * 1000 + j) ? "O" : grid[i][j]);
  //     }
  //     process.stdout.write("\n");
  //   }
  // }
  if (x === grid.length - 1 && y === grid[0].length - 2) ans = Math.max(ans, l);

  $: for (let [dx, dy] of dirs) {
    let visited = new Set(_visited);
    let l2 = l + 1;
    let nx = x + dx;
    let ny = y + dy;

    if (nx < 0 || nx >= grid.length || ny < 0 || ny >= grid[0].length) {
      continue;
    }

    let key = nx * 1000 + ny;

    if (visited.has(key)) {
      // console.log("visited", x, y, nx, ny, l2, [...visited].join(":"));
      continue;
    }

    visited.add(key);

    while (grid[nx][ny] in sloped) {
      let dir = sloped[grid[nx][ny] as keyof typeof sloped];
      nx += dirs[dir][0];
      ny += dirs[dir][1];
      key = nx * 1000 + ny;
      if (
        nx < 0 ||
        nx >= grid.length ||
        ny < 0 ||
        ny >= grid[0].length ||
        visited.has(key)
      ) {
        continue $;
      }
      visited.add(key);
      if (grid[nx][ny] === "#") {
        continue $;
      }
      ++l2;
    }

    if (grid[nx][ny] === "#") {
      continue;
    }

    // console.log(l2, nx, ny, [...visited].join(":"));

    q.push([l2, nx, ny, new Set(visited)]);
  }
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
