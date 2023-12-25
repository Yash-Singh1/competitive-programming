import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
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

// 1,0,1~1,2,1
// 0,0,2~2,0,2

console.log(JSON.stringify(bricks));

let stacking: number[][] = bricks.map((x) => []);
let stackit: number[][] = bricks.map((x) => []);
let brick2 = bricks.map((x) => [...x]);

for (let i = 0; i < bricks.length; i++) {
  let curz = bricks[i][0];
  let fell = false;
  let stacker = 0;
  for (let j = i - 1; j >= 0; --j) {
    if (fell) {
      // console.log(fell, j, bricks[j].slice(1), curz === bricks[j][0], canStack([...bricks[j].slice(1)], [...bricks[i].slice(1)]))
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
      // console.log('pls', bricks[i].slice(1), bricks[j].slice(1), [i, j])
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
  // console.log(bricks[i]);
  brick2[i] = bricks[i];
  // stacking[i] = stacker;
  // bricks = bricks.sort();
}

console.log(JSON.stringify(bricks));

stacking = stacking.map((x) => [...new Set(x)]);
stackit = stackit.map((x) => [...new Set(x)]);

console.log(JSON.stringify(stacking));
console.log(JSON.stringify(stackit));

let ansarr = bricks.map((x) => -1);

for (let j = 0; j < bricks.length; ++j) {
  let mp = new Map<number, number>();
  let tempstacking = [...stacking.map((x) => [...x])];
  function above(a: number) {
    // if (stacking[a] > 1) return 0;
    // if (mp.has(a)) return 0;
    // mp.set(a, 1);
    // if (ansarr[a] !== -1) return ansarr[a];
    // assert(stackit[a].every((x) => tempstacking[x].includes(a)));
    let ansi: number =
      1 +
      stackit[a].reduce((acc, x) => {
        tempstacking[x] = tempstacking[x].filter((y) => y !== a);
        return acc + (tempstacking[x].length > 0 ? 0 : above(x));
      }, 0);
    // mp.set(a, 1 + (mp.get(a) ?? 0));
    // console.log(a, ansi, stackit[a]);
    return ansi;
  }
  let canstackit = true;
  // console.log(j, stackit[j])
  for (const k of stackit[j]) {
    // console.log(j, k, stackit[k]);
    if (stackit[k].length === 1) {
      canstackit = false;
      break;
    }
  }
  // if (!canstackit) {
  // console.log(j);
  // ansarr[j] = ;
  let preans = ans;
  ans += above(j) - 1;
  // console.log("diff", ans - preans);
  // console.log(ans);
  // } else {
  //   // ansarr[j] = 0;
  // }
  // mp = new Map<number, number>();
}

// console.log(mp.values());

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
