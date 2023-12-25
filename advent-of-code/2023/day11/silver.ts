import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let grid: string[][] = [];

lines.forEach((line) => {
  if (!line.includes("#")) {
    grid.push(line.split(""));
  }
  grid.push(line.split(""));
});

for (let i = 0; i < grid[0].length; ++i) {
  let found = false;
  for (let j = 0; j < grid.length; ++j) {
    if (grid[j][i] === "#") {
      found = true;
      break;
    }
  }
  if (!found) {
    grid = grid.map((row) => {
      row = (row.join("").slice(0, i) + ".." + row.join("").slice(i + 1)).split(
        ""
      );
      return row;
    });
    ++i;
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

let mx = [0, 0, 1, -1];
let my = [1, -1, 0, 0];

for (let i = 0; i < galaxies.length; i++) {
  for (let j = i; j < galaxies.length; j++) {
    if (i === j) continue;
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
