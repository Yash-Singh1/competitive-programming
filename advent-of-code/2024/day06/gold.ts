// REALLY SLOW HAVE TO OPTIMIZE A LOT

import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

const spots = new Set<string>();

const oggrid = text.split("\n").map((s) => s.trim().split(""));
const guardPosog = [0, 0];
for (let i = 0; i < oggrid.length; i++) {
  for (let j = 0; j < oggrid[i].length; j++) {
    if (oggrid[i][j] === "^") {
      guardPosog[0] = i;
      guardPosog[1] = j;
    }
  }
}

function runThrough(pos: [number, number]) {
  let guardPos = [...guardPosog];
  let grid = [...oggrid.map((s) => [...s])];
  const mpVisited = new Set<string>();
  grid[pos[0]][pos[1]] = "#";
  let direction = 0;
  const mx = [0, 1, 0, -1];
  const my = [-1, 0, 1, 0];

  $: while (!mpVisited.has([...guardPos, direction].join(","))) {
    spots.add([...guardPos].join(","));
    mpVisited.add([...guardPos, direction].join(","));
    let nextPos = [guardPos[0] + my[direction], guardPos[1] + mx[direction]];
    while (
      nextPos[0] < 0 ||
      nextPos[0] >= grid.length ||
      nextPos[1] < 0 ||
      nextPos[1] >= grid[0].length ||
      grid[nextPos[0]][nextPos[1]] === "#"
    ) {
      if (
        nextPos[0] < 0 ||
        nextPos[0] >= grid.length ||
        nextPos[1] < 0 ||
        nextPos[1] >= grid[0].length
      ) {
        return false;
      }
      direction = (direction + 1) % 4;
      nextPos = [guardPos[0] + my[direction], guardPos[1] + mx[direction]];
    }
    guardPos[0] = nextPos[0];
    guardPos[1] = nextPos[1];
  }

  return true;
}

for (let i = 0; i < oggrid.length; i++) {
  for (let j = 0; j < oggrid[i].length; j++) {
    console.log(i, j)
    if (oggrid[i][j] === ".") {
      if (runThrough([i, j])) target++; 
    }
  }
}
// target = spots.size;

console.log(target);
