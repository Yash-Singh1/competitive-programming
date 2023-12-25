import assert, { fail } from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

type Brick = [number, number, number, number, number, number, number];

let bricks = lines
  .map((line) => {
    line = line.replace("~", ",");
    const [firstx, firsty, firstz, secondx, secondy, secondz] = line
      .split(",")
      .map(Number);
    return [firstz, firstx, firsty, firstz, secondx, secondy, secondz] as Brick;
  })
  .sort((a, b) => a[0] - b[0]) satisfies Brick[];

// console.log(bricks);

function canStack(a: Brick, b: Brick) {
  return (
    Math.max(a[1], b[1]) <= Math.min(a[4], b[4]) &&
    Math.max(a[2], b[2]) <= Math.min(a[5], b[5])
  );
}

let under: Set<number>[] = bricks.map(() => new Set());
let above: Set<number>[] = bricks.map(() => new Set());

for (let i = 0; i < bricks.length; i++) {
  let max_z = 1;
  for (let j = 0; j < i; ++j) {
    if (canStack(bricks[i], bricks[j])) {
      max_z = Math.max(max_z, bricks[j][6] + 1);
    }
  }
  bricks[i][0] = max_z;
  bricks[i][6] -= bricks[i][3] - max_z;
  bricks[i][3] = max_z;
}

for (let i = 0; i < bricks.length; i++) {
  for (let j = 0; j < i; ++j) {
    if (bricks[i][0] === bricks[j][6] + 1 && canStack(bricks[i], bricks[j])) {
      under[i].add(j);
      above[j].add(i);
    }
  }
}

console.log(bricks)

for (let j = bricks.length - 1; j >= 0; --j) {
  let tempunder = [...under.map((x) => [...x])];

  // if ([...above[j]].every((x) => under[x].size > 1)) {
  //   ++ans;
  // }

  let q: number[] = [j];

  let falling = new Set();
  falling.add(j);

  while (q.length > 0) {
    let cur = q.shift()!;

    for (const k of above[cur]) {
      if (falling.has(k)) continue;
      tempunder[k] = tempunder[k].filter((x) => x !== cur && !falling.has(x));
      if (tempunder[k].length === 0) {
        falling.add(k);
        q.push(k);
      }
    }
  }

  ans += falling.size - 1;
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
