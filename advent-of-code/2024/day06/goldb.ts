// Cleaned up and optimized

import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

const gridOG = text.split("\n").map((s) => s.trim().split(""));
const guardPosOG = [0, 0];
for (let i = 0; i < gridOG.length; i++) {
  for (let j = 0; j < gridOG[i].length; j++) {
    if (gridOG[i][j] === "^") {
      guardPosOG[0] = i;
      guardPosOG[1] = j;
    }
  }
}

const mx = [0, 1, 0, -1];
const my = [-1, 0, 1, 0];

function runThrough(pos: [number, number]) {
  let guardPos = [...guardPosOG];
  let grid = [...gridOG.map((s) => [...s])];
  const visited = new Set<string>();
  if (pos[0] >= 0) grid[pos[0]][pos[1]] = "#";
  let direction = 0;

  while (!visited.has([...guardPos, direction].join(","))) {
    visited.add([...guardPos, direction].join(","));
    let nextPos = [guardPos[0] + my[direction], guardPos[1] + mx[direction]];
    if (
      nextPos[0] < 0 ||
      nextPos[0] >= grid.length ||
      nextPos[1] < 0 ||
      nextPos[1] >= grid[0].length
    ) {
      if (pos[0] < 0) return visited;
      return false;
    }
    while (grid[nextPos[0]][nextPos[1]] === "#") {
      direction = (direction + 1) % 4;
      nextPos = [guardPos[0] + my[direction], guardPos[1] + mx[direction]];
    }
    guardPos[0] = nextPos[0];
    guardPos[1] = nextPos[1];
  }

  return true;
}

const visitedFirst = runThrough([-1, 0]) as Set<string>;

for (let i = 0; i < gridOG.length; i++) {
  for (let j = 0; j < gridOG[i].length; j++) {
    console.log(i, j);
    if (
      [0, 1, 2, 3].findIndex((d) => visitedFirst.has([i, j, d].join(","))) >= 0
    ) {
      if (runThrough([i, j])) target++;
    }
  }
}

console.log(target);
