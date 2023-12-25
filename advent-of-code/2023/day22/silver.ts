import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

let bricks = lines
  .map((line) => {
    let [first, second] = line.split("~");
    let [firstx, firsty, firstz] = first.split(",").map((x) => parseInt(x));
    let [secondx, secondy, secondz] = second.split(",").map((x) => parseInt(x));
    if (firstz > secondz) {
      [firstz, secondz] = [secondz, firstz];
    }
    return [firstz, [firstx, firsty, firstz], [secondx, secondy, secondz]] as [
      number,
      [number, number, number],
      [number, number, number]
    ];
  })
  .sort();

function canStack(
  a: [[number, number, number], [number, number, number]],
  b: [[number, number, number], [number, number, number]]
) {
  if (a[0][0] > a[1][0]) a[0][0] = a[1][0];
  if (a[0][1] > a[1][1]) a[0][1] = a[1][1];
  if (b[0][0] > b[1][0]) b[0][0] = b[1][0];
  if (b[0][1] > b[1][1]) b[0][1] = b[1][1];
  // if a is a line from a[0] = (x1, y1, z1) to a[1] = (x2, y2, z2)
  // and b is a line from b[0] = (x3, y3, z3) to b[1] = (x4, y4, z4)
  // return boolean determining if a can stack on b
  for (let i = 0; i < 10; ++i) {
    for (let j = 0; j < 10; ++j) {
      let afinish = false;
      assert(a[0][0] <= a[1][0] && a[0][1] <= a[1][1]);
      assert(b[0][0] <= b[1][0] && b[0][1] <= b[1][1]);
      if (a[0][0] <= i && i <= a[1][0] && a[0][1] <= j && j <= a[1][1]) {
        afinish = true;
      }
      let bfinish = false;
      if (b[0][0] <= i && i <= b[1][0] && b[0][1] <= j && j <= b[1][1]) {
        bfinish = true;
      }
      if (afinish && bfinish) {
        return true;
      }
    }
  }
  return false;
}

let stacking: number[][] = bricks.map((x) => []);
let stackit: number[][] = bricks.map((x) => []);
let brick2 = bricks.map((x) => [...x]);

for (let i = 0; i < bricks.length; i++) {
  let curz = bricks[i][0];
  let fell = false;
  for (let j = i - 1; j >= 0; --j) {
    if (fell) {
      if (
        curz - 1 === bricks[j][0] &&
        canStack(
          [...bricks[j].slice(1)] as [
            [number, number, number],
            [number, number, number]
          ],
          [...bricks[i].slice(1)] as [
            [number, number, number],
            [number, number, number]
          ]
        )
      ) {
        stacking[i].push(j);
        stackit[j].push(i);
      } else if (curz > bricks[j][0]) {
        break;
      }
      continue;
    }
    if (
      curz > bricks[j][0] &&
      canStack(
        [...bricks[j].slice(1)] as [
          [number, number, number],
          [number, number, number]
        ],
        [...bricks[i].slice(1)] as [
          [number, number, number],
          [number, number, number]
        ]
      )
    ) {
      curz = bricks[j][0] + 1;
      fell = true;
      stacking[i].push(j);
      stackit[j].push(i);
    }
  }
  if (!fell) {
    curz = 0;
  }
  bricks[i][0] = curz;
  bricks[i][1][2] = curz;
  bricks[i][2][2] = curz;
  brick2[i] = bricks[i];
}

stacking = stacking.map((x) => [...new Set(x)]);
stackit = stackit.map((x) => [...new Set(x)]);

for (let j = 0; j < bricks.length; ++j) {
  let canstackit = true;
  for (const k of stackit[j]) {
    if (stacking[k].length === 1) {
      canstackit = false;
      break;
    }
  }
  if (canstackit) {
    ++ans;
  }
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
