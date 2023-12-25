import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let mx = [0, 1, 0, -1];
let my = [1, 0, -1, 0];

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
let points: [number, number][] = [[0, 0]];
let hashes = 0;

lines.forEach((line) => {
  let [dir, num, color] = line.split(" ");
  color = color.slice(2, -1);
  console.log(color)
  let numVal = parseInt(color.slice(0, -1), 16);
  console.log(numVal)
  let rldir = Number(color[color.length - 1]);
  curx += mx[rldir] * numVal;
  cury += my[rldir] * numVal;
  hashes += numVal;
  points.push([curx, cury]);
});

console.log(points)

let j = points.length-1;
points.forEach((point, idx) => {
  let [x, y] = point;
  let [x2, y2] = points[j];
  // ans += (x+x2)*(y2-y)
  ans += x*(y2-points[(idx+1)%points.length][1]);
  j = idx;
});

ans = Math.floor(Math.abs(ans)/2);

let ansi = ans - Math.floor(hashes / 2) + 1

console.log(hashes + ansi);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
