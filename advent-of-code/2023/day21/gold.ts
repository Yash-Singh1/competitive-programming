import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

let times = 10;

let grid = lines.map((line) => line.split(""));
// let grid: string[][] = [];
// for (let i = 0; i < times; i++) {
//   grid = grid.concat([
//     // ...(i
//     //   ? [
//     //       ".".repeat(gridn.length * times + (times - 1) * 2).split(""),
//     //       ".".repeat(gridn.length * times + (times - 1) * 2).split(""),
//     //     ]
//     //   : []),
//     ...gridn.map((line) =>
//       Array.from(new Array(times))
//         .map(() => line.join(""))
//         .join("")
//         .split("")
//     ),
//   ]);
// }

let startpos = [0, 0];
// $: for (let i = (gridn.length + 2) * Math.floor(times / 2); i < grid.length; i++) {
//   for (let j = (gridn[0].length + 2) * Math.floor(times / 2); j < grid[0].length; j++) {
$: for (let i = 0; i < grid.length; i++) {
  for (let j = 0; j < grid.length; j++) {
    if (grid[i][j] === "S") {
      startpos = [i, j];
      break $;
    }
  }
}

grid = grid.map((line) => line.map((c) => (c === "S" ? "." : c)));

let q = [];
q.push([startpos[0], startpos[1], 0]);

let stepsin = grid.map((line) => line.map(() => -1));

const MAX_STEPS = 64;
let width = 2*MAX_STEPS+1;

let upp = startpos[0];
let down = startpos[0];
console.log(width, upp, down)
for (let i = width; i >= 0; i -= 2) {
  upp %= grid.length;
  down += grid.length;
  down %= grid.length;
  let preans = ans;
  let lefti = ((i-width)%grid[0].length);
  if (lefti < 0) {
    lefti = (grid[0].length-Math.abs(lefti))%grid[0].length;
  }
  for (let j = startpos[1]-Math.floor(i/2); j <= startpos[1]+Math.floor(i/2); j += 2) {
    let lefti = j%grid[0].length;
    if (lefti < 0) {
      lefti = (grid[0].length-Math.abs(lefti))%grid[0].length;
    } 
    console.log([upp, down, lefti], grid[upp][lefti], grid[down][lefti])
    if (grid[upp][lefti] === "#") {
    } else {
      ++ans;
    }
    if (grid[down][lefti] === "#") {
    } else if (upp !== down) {
      ++ans;
    }
  }
  console.log(ans-preans, upp, i)
  upp++;
  down--;
}

let minx = startpos[0];
let maxx = startpos[0];

for (let i = 0; i < grid.length; i++) {
  let str = "";
  for (let j = 0; j < grid[0].length; j++) {
    if (stepsin[i][j] % 2 === MAX_STEPS % 2) {
      str += "O";
    } else {
      if (typeof grid[i][j] === "undefined") {
        console.log([i, j]);
      }
      if (startpos[0] === i && startpos[1] === j) {
        str += "S";
        continue;
      }
      str += grid[i][j];
    }
  }
  console.log(str);
}

// for (let i = 0; i < grid.length; i++) {
//   for (let j = 0; j < grid.length; j++) {
//     if (stepsin[i][j] % 2 === 0 && grid[i][j] === ".") {
//       ++ans;
//     }
//   }
// }
// console.log(maxx-minx+1);

console.log(ans-1);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
