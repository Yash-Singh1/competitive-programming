import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let grid = lines.map((line) => line.split(""));
// console.log(grid);
let starters: [number, number, number][] = [];
for (let i = 0; i < grid.length; i++) {
  starters.push([i, 0, 0]);
  starters.push([i, grid.length - 1, 1]);
}

for (let i = 0; i < grid[0].length; i++) {
  starters.push([0, i, 2]);
  starters.push([grid.length - 1, i, 3]);
}

for (const starter of starters) {
  // console.log(starter)
  let energized = lines.map((line) => line.split("").map((c) => false));
  // console.log(energized)
  energized[starter[0]][starter[1]] = true;
  let visited = lines.map((line) =>
    line.split("").map((c) => [false, false, false, false])
  );
  let mx = [0, 0, 1, -1];
  let my = [1, -1, 0, 0];
  let q = [starter];
  let nextd = 0;

  while (q.length > 0) {
    let [x, y, d] = q.shift()!;
    if (x + mx[d] < 0 || x + mx[d] >= grid.length) continue;
    if (y + my[d] < 0 || y + my[d] >= grid.length) continue;
    if (visited[x][y][d]) continue;
    visited[x][y][d] = true;
    switch (grid[x + mx[d]][y + my[d]]) {
      case ".":
        if (!visited[x + mx[d]][y + my[d]][d])
          q.push([x + mx[d], y + my[d], d]);
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

  let minans = 0;
  for (let i = 0; i < energized.length; i++) {
    let line = "";
    for (let j = 0; j < energized[i].length; j++) {
      if (energized[i][j]) minans++;
      if (energized[i][j]) line += "#";
      else line += ".";
    }
    // console.log(line);
  }

  if (minans > ans) {
    // console.log(minans);
    // console.log(starter);
    for (let i = 0; i < energized.length; i++) {
      let line = "";
      for (let j = 0; j < energized[i].length; j++) {
        if (energized[i][j]) line += "#";
        else line += ".";
      }
      // console.log(line);
    }
  }

  ans = Math.max(ans, minans);
}

console.log(ans);
// fs.writeFileSync(
//   "out.txt",
//   fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
// );
