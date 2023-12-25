import { argv } from "bun";
import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

let times = Math.ceil((Number(argv[3]) * 3) / lines[0].length);

let gridn = lines.map((line) => line.split(""));
let grid: string[][] = [];
for (let i = 0; i < times; i++) {
  grid = grid.concat([
    // ...(i
    //   ? [
    //       ".".repeat(gridn.length * times + (times - 1) * 2).split(""),
    //       ".".repeat(gridn.length * times + (times - 1) * 2).split(""),
    //     ]
    //   : []),
    ...gridn.map((line) =>
      Array.from(new Array(times))
        .map(() => line.join(""))
        .join("")
        .split("")
    ),
  ]);
}

let startpos = [0, 0];
$: for (let i = (gridn.length + 2) * Math.floor((times-1) / 2); i < grid.length; i++) {
  for (let j = (gridn[0].length + 2) * Math.floor((times-1) / 2); j < grid[0].length; j++) {
// $: for (let i = 0; i < grid.length; i++) {
//   for (let j = 0; j < grid.length; j++) {
    if (grid[i][j] === "S") {
      startpos = [i, j];
      break $;
    }
  }
}

grid = grid.map((line) => line.map((c) => (c === "S" ? "." : c)));

const MAX_STEPS = Number(argv[3]);
let width = 2*MAX_STEPS+1;

let q = [];
q.push([startpos[0], startpos[1], 0]);

let stepsin = grid.map((line) => line.map(() => -1));

while (q.length > 0) {
  let [x, y, steps] = q.shift()!;
  // console.log([x, y, steps])
  if (steps === MAX_STEPS) {
    continue;
  }
  for (let [dx, dy] of [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
  ]) {
    let nx = x + dx;
    let ny = y + dy;
    if (nx < 0 || nx >= grid.length || ny < 0 || ny >= grid.length) {
      continue;
    }
    if (grid[nx][ny] === "#") {
      continue;
    }
    if (stepsin[nx][ny] === -1) {
      stepsin[nx][ny] = steps + 1;
      q.push([nx, ny, steps + 1]);
    }
  }
}

// const mp = {}

// console.log(startpos)
// let upp = startpos[0];
// let down = startpos[0];
// console.log(width, upp, down)
// for (let i = width; i >= 0; i -= 2) {
//   upp %= grid.length;
//   down += grid.length;
//   down %= grid.length;
//   let preans = ans;
//   // let lefti = ((i-width)%grid[0].length);
//   // if (lefti < 0) {
//   //   lefti = (grid[0].length-Math.abs(lefti))%grid[0].length;
//   // }
//   let dans = 0;
//   console.log(startpos[1]-Math.floor(i/2), startpos[1]+Math.floor(i/2))
//   for (let j = startpos[1]-Math.floor(i/2); j <= startpos[1]+Math.floor(i/2); j += 2) {
//     let lefti = j%grid[0].length;
//     if (lefti < 0) {
//       lefti = (grid[0].length-Math.abs(lefti))%grid[0].length;
//     }
//     console.log([upp, down, lefti], grid[upp][lefti], grid[down][lefti])
//     if (grid[upp][lefti] === "#") {
//     } else {
//       ++ans;
//     }
//     if (grid[down][lefti] === "#") {
//     } else if (upp !== down) {
//       ++dans;
//     }
//   }
//   mp[upp] = ans-preans;
//   mp[down] = dans;
//   console.log(ans-preans, dans, upp, i)
//   ans += dans;
//   upp++;
//   down--;
// }

// console.log([...Object.values(mp)].join('\n'))

// let minx = startpos[0];
// let maxx = startpos[0];

ans = 0
for (let i = 0; i < grid.length; i++) {
  let str = "";
  for (let j = 0; j < grid[0].length; j++) {
    if (startpos[0] === i && startpos[1] === j) {
      str += "S";
      ans += 1 -(MAX_STEPS % 2);
      continue;
    }
    if (stepsin[i][j] % 2 === MAX_STEPS % 2) {
      str += "O";
      ++ans;
    } else {
      if (typeof grid[i][j] === "undefined") {
        console.log([i, j]);
      }
      str += grid[i][j];
    }
  }
  console.log(str);
}


for (let i = 0; i < grid.length; i++) {
  for (let j = 0; j < grid.length; j++) {
    if (stepsin[i][j] % 2 === MAX_STEPS % 2 && grid[i][j] === ".") {
      // ++ans;
    }
  }
}
// console.log(maxx-minx+1);

console.log(ans);

let x = 202300;
console.log(Math.pow(x, 2) * 14898 + x * 14997 + 3770)
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
