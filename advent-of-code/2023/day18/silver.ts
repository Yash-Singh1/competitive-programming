import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let mx = [0, 0, -1, 1];
let my = [-1, 1, 0, 0];

let dirma: Record<string, 1 | 2 | 3 | 0> = {
  U: 2,
  D: 3,
  L: 0,
  R: 1,
};

let maxwidth = 1;
let maxheight = 1;
let curx = 0;
let cury = 0;

lines.forEach((line) => {
  let [dir, num, color] = line.split(" ");
  let numVal = parseInt(num, 10);
  curx += mx[dirma[dir]] * numVal;
  cury += my[dirma[dir]] * numVal;
  maxwidth = Math.max(maxwidth, cury + 1);
  maxheight = Math.max(maxheight, curx + 1);
});

let grid = Array.from(Array(1000)).map(() =>
  Array.from(Array(1000)).map(() => ".")
);
grid[0][0] = "#";

curx = 500;
cury = 500;

let mnfound = Infinity;
let mnfound2 = Infinity;
let mxfound = -Infinity;
let mxfound2 = new Map<number, number>();

lines.forEach((line) => {
  let [dir, num, color] = line.split(" ");
  let numVal = parseInt(num, 10);
  for (let i = 0; i < numVal; i++) {
    curx += mx[dirma[dir]];
    mnfound = Math.min(mnfound, curx);
    mxfound = Math.max(mxfound, curx);
    cury += my[dirma[dir]];
    mxfound2.set(curx, Math.max(mxfound2.get(curx) || 0, cury));
    mnfound2 = Math.min(mnfound2, cury);
    // console.log(curx, cury);
    grid[curx][cury] = "#";
  }
});

// console.log(grid)

let seen = new Set<string>();
let q = [[0, 0]];
while (q.length) {
  let [x, y] = q.shift()!;
  if (seen.has(`${x},${y}`)) continue;
  seen.add(`${x},${y}`);
  for (let i = 0; i < 4; i++) {
    let nx = x + mx[i];
    let ny = y + my[i];
    if (nx < 0 || nx >= 1000 || ny < 0 || ny >= 1000) continue;
    if (grid[nx][ny] !== "#") {
      q.push([nx, ny]);
    }
  }
}

ans = 1000 * 1000 - seen.size;

// let inside = false;
// for (let i = 1; i < 1000; i++) {
//   // console.log(i, mxfound2.get(i));
//   for (let j = 1; j <= (mxfound2.get(i) || 0); ++j) {
//     // if (!grid[i].slice(j+1).findIndex((s) => s==='#')) {
//     //   break;
//     // }
//     if (grid[i][j] === "#") {
//       assert(["#", "."].includes(grid[i][j - 1]));
//       if (grid[i][j - 1] === ".") inside = !inside;
//       console.log(i, j);
//       ++ans;
//     } else if (inside) {
//       console.log(i, j);
//       grid[i][j] = "#";
//       ++ans;
//     }
//   }
//   inside = false;
// }

// for (let i = 0; i < 1000; i++) {
//   for (let j = 0; j < 1000; j++) {
//     process.stdout.write(grid[i][j]);
//   }
//   process.stdout.write("\n");
// }

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
