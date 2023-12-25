import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let grid = lines.map((line) => line.split(""));

for (let j = 0; j < grid[0].length; ++j) {
  for (let k = 0; k < grid.length; ++k) {
    for (let i = 1; i < grid.length; ++i) {
      if (grid[i][j] === "O") {
        if (grid[i - 1][j] === ".") {
          grid[i - 1][j] = "O";
          grid[i][j] = ".";
        }
      }
    }
  }
  // console.log(grid.map((l) => l.join("")).join("\n"));
  // console.log()
  // console.log()
}

console.log(grid.map((l) => l.join("")).join("\n"));

let done = grid[0].map((c) => false);

for (let i = 0; i < grid.length; ++i) {
  for (let j = 0; j < grid[i].length; ++j) {
    // if (grid[i][j] === "#") {
    //   done[j] = true;
    // }
    if (!done[j] && grid[i][j] === "O") {
      ans += grid.length - i;
      console.log(i)
    }
  }
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
