import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

const mpVisited = new Set<string>();
const spots = new Set<string>();

const grid = text.split("\n").map((s) => s.trim().split(""));
const guardPos = [0, 0];
for (let i = 0; i < grid.length; i++) {
  for (let j = 0; j < grid[i].length; j++) {
    if (grid[i][j] === "^") {
      guardPos[0] = i;
      guardPos[1] = j;
    }
  }
}

let direction = 0;
const mx = [0, 1, 0, -1];
const my = [-1, 0, 1, 0];

$: while (!mpVisited.has([...guardPos, direction].join(","))) {
  // for (let i = 0; i < grid.length; i++) {
  //   let line = "";
  //   for (let j = 0; j < grid[i].length; j++) {
  //     if ([i, j].join(",") === [guardPos[0], guardPos[1]].join(",")) {
  //       line += "^";
  //       continue;
  //     }
  //     if (spots.has([i, j].join(","))) {
  //       line += "X";
  //     } else {
  //       line += grid[i][j];
  //     }
  //   }
  //   console.log(line);
  // }
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
      break $;
    }
    direction = (direction + 1) % 4;
    nextPos = [guardPos[0] + my[direction], guardPos[1] + mx[direction]];
  }
  guardPos[0] = nextPos[0];
  guardPos[1] = nextPos[1];
}

spots.add([...guardPos].join(","));
target = spots.size;

console.log(target);
