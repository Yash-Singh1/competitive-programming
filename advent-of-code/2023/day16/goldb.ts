import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let grid = lines.map((line) => line.split(""));

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
  let energized = grid.map((line) => line.map(() => false));
  energized[starter[0]][starter[1]] = true;
  let visited = grid.map((line) =>
    line.map(() => [false, false, false, false])
  );
  let mx = [0, 0, 1, -1];
  let my = [1, -1, 0, 0];
  let q = [starter];

  while (q.length > 0) {
    let [x, y, d] = q.shift()!;
    if (x + mx[d] < 0 || x + mx[d] >= grid.length) continue;
    if (y + my[d] < 0 || y + my[d] >= grid[0].length) continue;
    if (visited[x][y][d]) continue;
    visited[x][y][d] = true;
    energized[x + mx[d]][y + my[d]] = true;
    let newd1 = -1,
      newd2 = -1;
    switch (grid[x + mx[d]][y + my[d]]) {
      case ".":
        newd1 = d;
        break;
      case "|":
        if (d >= 2) {
          newd1 = d;
        } else {
          newd1 = 2;
          newd2 = 3;
        }
        break;
      case "-":
        if (d <= 1) {
          newd1 = d;
        } else {
          newd1 = 0;
          newd2 = 1;
        }
        break;
      case "/":
        newd1 = (d + (d % 2 ? 1 : -1) + 4) % 4;
        break;
      case "\\":
        newd1 = (d + 2) % 4;
        break;
    }

    for (const newd of [newd1, newd2]) {
      if (newd === -1) break;
      if (!visited[x + mx[d]][y + my[d]][newd])
        q.push([x + mx[d], y + my[d], newd]);
    }
  }

  let minans = 0;
  for (let i = 0; i < energized.length; i++) {
    for (let j = 0; j < energized[i].length; j++) {
      if (energized[i][j]) {
        ++minans;
      }
    }
  }

  ans = Math.max(ans, minans);
}

console.log(ans);
