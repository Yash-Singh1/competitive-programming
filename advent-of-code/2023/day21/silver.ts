import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

let grid = lines.map((line) => line.split(""));
let startpos = [0, 0];
for (let i = 0; i < grid.length; i++) {
  for (let j = 0; j < grid.length; j++) {
    if (grid[i][j] === "S") {
      startpos = [i, j];
      break;
    }
  }
}

grid[startpos[0]][startpos[1]] = ".";

let q = [];
q.push([startpos[0], startpos[1], 0]);

let stepsin = grid.map((line) => line.map(() => 0));
let maxstepdone = grid.map((line) => line.map(() => -1));

const MAX_STEPS = 50;

while (q.length > 0) {
  let [x, y, steps] = q.shift()!;
  // console.log([x, y, steps])
  if (steps === MAX_STEPS) {
    break;
  }
  if (steps < stepsin[x][y]) {
    continue;
  }
  if (maxstepdone[x][y] >= steps) {
    continue;
  }
  maxstepdone[x][y] = steps;
  for (let [dx, dy] of [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
  ]) {
    let nx = x + dx;
    let ny = y + dy;
    if (nx < 0 || nx >= grid.length || ny < 0 || ny >= grid.length) {
      continue;
    }
    if (grid[nx][ny] === "#") {
      continue;
    }
    stepsin[nx][ny] = steps + 1;
    q.push([nx, ny, steps + 1]);
  }
}

for (let i = 0; i < grid.length; i++) {
  let str = "";
  for (let j = 0; j < grid.length; j++) {
    if (stepsin[i][j] === MAX_STEPS) {
      str += "O";
    } else {
      str += grid[i][j];
    }
  }
  console.log(str);
}

for (let i = 0; i < grid.length; i++) {
  for (let j = 0; j < grid.length; j++) {
    if (stepsin[i][j] === MAX_STEPS && grid[i][j] === ".") {
      ++ans;
    }
  }
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
