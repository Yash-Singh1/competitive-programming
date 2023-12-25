import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let grid = lines.map((line) => line.split(""));
// console.log(grid);

let energized = lines.map((line) => line.split("").map((c) => false));
// console.log(energized)
energized[0][0] = true;
let visited = lines.map((line) =>
  line.split("").map((c) => [false, false, false, false])
);
let mx = [0, 0, 1, -1];
let my = [1, -1, 0, 0];
let q = [[0, 0, 0]];
let nextd = 0;

while (q.length > 0) {
  let [x, y, d] = q.shift()!;
  if (x + mx[d] < 0 || x + mx[d] >= grid.length) continue;
  if (y + my[d] < 0 || y + my[d] >= grid.length) continue;
  if (visited[x][y][d]) continue;
  visited[x][y][d] = true;
  switch (grid[x + mx[d]][y + my[d]]) {
    case ".":
      if (!visited[x + mx[d]][y + my[d]][d]) q.push([x + mx[d], y + my[d], d]);
      energized[x + mx[d]][y + my[d]] = true;
      break;
    case "|":
      if (d >= 2) {
        if (!visited[x + mx[d]][y + my[d]][d])
          q.push([x + mx[d], y + my[d], d]);
        // visited[x + mx[d]][y + my[d]][d] = true;
        energized[x + mx[d]][y + my[d]] = true;
      } else {
        if (!visited[x + mx[d]][y + my[d]][2])
          q.push([x + mx[d], y + my[d], 2]);
        // visited[x + mx[d]][y + my[d]][2] = true;
        if (!visited[x + mx[d]][y + my[d]][3])
          q.push([x + mx[d], y + my[d], 3]);
        // visited[x + mx[d]][y + my[d]][3] = true;
        energized[x + mx[d]][y + my[d]] = true;
      }
      break;
    case "-":
      if (d <= 1) {
        if (!visited[x + mx[d]][y + my[d]][d])
          q.push([x + mx[d], y + my[d], d]);
        // visited[x + mx[d]][y + my[d]][d] = true;
        energized[x + mx[d]][y + my[d]] = true;
      } else {
        if (!visited[x + mx[d]][y + my[d]][0])
          q.push([x + mx[d], y + my[d], 0]);
        // visited[x + mx[d]][y + my[d]][0] = true;
        if (!visited[x + mx[d]][y + my[d]][1])
          q.push([x + mx[d], y + my[d], 1]);
        // visited[x + mx[d]][y + my[d]][1] = true;
        energized[x + mx[d]][y + my[d]] = true;
      }
      break;
    case "/":
      if (d === 0) {
        nextd = 3;
      } else if (d === 1) {
        nextd = 2;
      } else if (d === 2) {
        nextd = 1;
      } else if (d === 3) {
        nextd = 0;
      }
      if (!visited[x + mx[d]][y + my[d]][nextd])
        q.push([x + mx[d], y + my[d], nextd]);
      // visited[x + mx[d]][y + my[d]][nextd] = true;
      energized[x + mx[d]][y + my[d]] = true;
      break;
    case "\\":
      if (d === 0) {
        nextd = 2;
      } else if (d === 1) {
        nextd = 3;
      } else if (d === 2) {
        nextd = 0;
      } else if (d === 3) {
        nextd = 1;
      }
      if (!visited[x + mx[d]][y + my[d]][nextd])
        q.push([x + mx[d], y + my[d], nextd]);
      // visited[x + mx[d]][y + my[d]][nextd] = true;
      energized[x + mx[d]][y + my[d]] = true;
      break;
  }
}

// console.log(energized);

for (let i = 0; i < energized.length; i++) {
  let line = "";
  for (let j = 0; j < energized[i].length; j++) {
    if (energized[i][j]) ans++;
    if (energized[i][j]) line += "#";
    else line += ".";
  }
  // console.log(line);
}

console.log(ans);
// fs.writeFileSync(
//   "out.txt",
//   fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
// );
