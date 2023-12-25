import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let grid: string[][] = [];

let increaseRows: number[] = [];

lines.forEach((line, idx) => {
  if (!line.includes("#")) {
    increaseRows.push(idx);
  }
  grid.push(line.split(""));
});

let increaseCols: number[] = [];

for (let i = 0; i < grid[0].length; ++i) {
  let found = false;
  for (let j = 0; j < grid.length; ++j) {
    if (grid[j][i] === "#") {
      found = true;
      break;
    }
  }
  if (!found) {
    increaseCols.push(i);
  }
}

let galaxies = [];
for (let i = 0; i < grid.length; i++) {
  for (let j = 0; j < grid[i].length; j++) {
    if (grid[i][j] === "#") {
      galaxies.push([i, j]);
    }
  }
}

for (let i = 0; i < galaxies.length; i++) {
  for (let j = i; j < galaxies.length; j++) {
    if (i === j) continue;
    for (let k = 0; k < increaseRows.length; ++k) {
      if (
        (galaxies[i][0] < increaseRows[k] &&
          galaxies[j][0] > increaseRows[k]) ||
        (galaxies[i][0] > increaseRows[k] && galaxies[j][0] < increaseRows[k])
      ) {
        ans += 1000000-1;
      }
    }
    for (let k = 0; k < increaseCols.length; ++k) {
      if (
        (galaxies[i][1] < increaseCols[k] &&
          galaxies[j][1] > increaseCols[k]) ||
        (galaxies[i][1] > increaseCols[k] && galaxies[j][1] < increaseCols[k])
      ) {
        ans += 1000000-1;
      }
    }
    ans +=
      Math.abs(galaxies[i][0] - galaxies[j][0]) +
      Math.abs(galaxies[i][1] - galaxies[j][1]);
  }
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
