import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let start = lines[0];
let grid = lines.slice(1).map((line) => line.split(""));
let startpos = [0, 0] as [number, number];
for (let i = 0; i < grid.length; ++i) {
  for (let j = 0; j < grid[i].length; ++j) {
    if (grid[i][j] === "S") {
      startpos = [i, j];
      grid[i][j] = start;
    }
  }
}

let distance = lines.slice(1).map((line) => line.split("").map(() => -1));

let q: [number, number][] = [startpos];
let my = [0, 0, 1, -1];
let mx = [1, -1, 0, 0];
let pipemp: Record<string, number[]> = {
  "|": [0, 1],
  "-": [2, 3],
  L: [1, 2],
  J: [1, 3],
  "7": [0, 3],
  F: [0, 2],
};

distance[startpos[0]][startpos[1]] = 0;

while (q.length > 0) {
  let [x, y] = q.pop()!;
  let curval = grid[x][y];
  for (let i = 0; i < 4; ++i) {
    let nx = x + mx[i];
    let ny = y + my[i];
    // console.log(
    //   i,
    //   pipemp[curval].includes(i),
    //   [nx, ny],
    //   curval
    // );
    if (!pipemp[curval].includes(i)) continue;
    if (
      nx >= 0 &&
      nx < grid.length &&
      ny >= 0 &&
      ny < grid[nx].length &&
      grid[nx][ny] !== "." &&
      (distance[x][y] + 1 < distance[nx][ny] || distance[nx][ny] === -1)
    ) {
      distance[nx][ny] = distance[x][y] + 1;
      q.push([nx, ny]);
    }
  }
}

for (let i = 0; i < distance.length; ++i) {
  for (let j = 0; j < distance[i].length; ++j) {
    ans = Math.max(ans, distance[i][j])
  }
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
