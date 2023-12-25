import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let grid = lines.map((line) => line.split(""));

let mx = [-1, 0, 1, 0];
let my = [0, -1, 0, 1];

const prevs = [];

function runCycle() {
  // console.log(1);
  for (let j = 0; j < grid[0].length; ++j) {
    let i = 0;
    while (i < grid.length) {
      let os = 0;
      let orig = i;
      while (i < grid.length && grid[i][j] !== "#") {
        if (grid[i][j] === "O") os++;
        i++;
      }
      for (let k = orig; k < orig + os; ++k) {
        grid[k][j] = "O";
      }
      for (let k = orig + os; k < i; ++k) {
        grid[k][j] = ".";
      }
      ++i;
    }
  }
  // console.log(grid.map((l) => l.join("")).join("\n"));
  // // console.log(2);
  for (let i = 0; i < grid.length; ++i) {
    let j = grid[0].length - 1;
    while (j >= 0) {
      let os = 0;
      let orig = j;
      while (j >= 0 && grid[i][j] !== "#") {
        if (grid[i][j] === "O") os++;
        --j;
      }
      for (let k = j+1; k < j+1+os; ++k) {
        grid[i][k] = "O";
      }
      for (let k = j+1+os; k <= orig; ++k) {
        grid[i][k] = ".";
      }
      --j;
    }
  }
  // console.log("\n")
  // console.log(grid.map((l) => l.join("")).join("\n"));

  // // console.log(3);
  for (let j = 0; j < grid[0].length; ++j) {
    let i = grid.length - 1;
    while (i >= 0) {
      let os = 0;
      let orig = i;
      while (i >= 0 && grid[i][j] !== "#") {
        if (grid[i][j] === "O") os++;
        --i;
      }
      for (let k = orig; k > orig - os; --k) {
        grid[k][j] = "O";
      }
      // // console.log(3.5)
      for (let k = orig - os; k > i; --k) {
        grid[k][j] = ".";
      }
      // // console.log(3.6)
      --i;
    }
  }
  // console.log("\n")
  // console.log(grid.map((l) => l.join("")).join("\n"));
  // // console.log(4);
  for (let i = 0; i < grid.length; ++i) {
    let j = 0;
    while (j < grid[i].length) {
      let os = 0;
      let orig = j;
      while (j < grid.length && grid[i][j] !== "#") {
        if (grid[i][j] === "O") os++;
        ++j;
      }
      for (let k = j-1; k > j-1-os; --k) {
        grid[i][k] = "O";
      }
      for (let k = j-1-os; k >= orig; --k) {
        grid[i][k] = ".";
      }
      ++j;
    }
  }
  // console.log("\n")
  // console.log(grid.map((l) => l.join("")).join("\n"));
}

for (let i = 0; i < 2000; ++i) {
  runCycle();
  let idx;
  if ((idx = prevs.indexOf(grid.map((l) => l.join("")).join("\n"))) !== -1) {
    console.log("Match found!");
    grid = prevs[((1000000000 - idx) % (i - idx)) + idx - 1]
      .split("\n")
      .map((l) => l.split(""));
    break;
  } else prevs.push(grid.map((l) => l.join("")).join("\n"));
}

let done = grid[0].map((c) => false);

for (let i = 0; i < grid.length; ++i) {
  for (let j = 0; j < grid[i].length; ++j) {
    // if (grid[i][j] === "#") {
    //   done[j] = true;
    // }
    if (!done[j] && grid[i][j] === "O") {
      ans += grid.length - i;
      // console.log(i);
    }
  }
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
