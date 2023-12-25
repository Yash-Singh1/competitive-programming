import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let grid = lines.map((line) => line.split("").map((c) => parseInt(c)));
let mx = [0, 0, 1, -1];
let my = [1, -1, 0, 0];

let q: [number, number, number, number][][] = [1, 2, 3, 4, 5, 6, 7, 8, 9].map(() => []);
let min = grid.map((line) =>
  line.map(
    () =>
      [
        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10].map(() => Infinity),
        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10].map(() => Infinity),
        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10].map(() => Infinity),
        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10].map(() => Infinity),
      ] as number[][]
  )
);
for (let i = 0; i < 4; ++i) {
  min[0][0][i][10] = 0;
  q[0].push([0, 0, 10, i]);
}
while (true) {
  let qidx = 0;
  while (qidx < q.length && q[qidx].length == 0) {
    qidx++;
  }
  if (qidx == q.length) {
    break;
  }

  let [x, y, left, d] = q[qidx].shift()!;

  // if (x == grid.length - 1 && y == grid[0].length - 1) {
  //   break;
  // }
  // console.log(min[x][y][d][0], min[x][y][d][1], x, y, left, d);
  if (left > 0) {
    // if (min[x][y][d][left] < min[x][y][d][left - 1]) {
    //   q.push([x, y, left - 1, d]);
    //   min[x][y][d][left - 1] = min[x][y][d][left];
    // }
    if (
      x + mx[d] >= 0 &&
      x + mx[d] < grid.length &&
      y + my[d] >= 0 &&
      y + my[d] < grid[0].length
    ) {
      if (
        min[x][y][d][left] + grid[x + mx[d]][y + my[d]] <
        min[x + mx[d]][y + my[d]][d][left - 1]
      ) {
        q[grid[x + mx[d]][y + my[d]]-1].push([x + mx[d], y + my[d], left - 1, d]);
        min[x + mx[d]][y + my[d]][d][left - 1] =
          min[x][y][d][left] + grid[x + mx[d]][y + my[d]];
      }
    }
  }
  if (left <= 6) {
    for (let k = 0; k < 4; ++k) {
      if (
        k != d &&
        ((Math.min(d, k) & 1) || Math.max(d, k) - Math.min(d, k) !== 1)
        // (d & 1) === (k & 1) &&
        // !(
        //   (d === 2 && k === 3) ||
        //   (d === 3 && k === 2) ||
        //   (d === 0 && k === 1) ||
        //   (d === 1 && k === 0)
        // )
      ) {
        if (
          x + mx[k] >= 0 &&
          x + mx[k] < grid.length &&
          y + my[k] >= 0 &&
          y + my[k] < grid[0].length
        ) {
          if (
            min[x][y][d][left] + grid[x + mx[k]][y + my[k]] <
            min[x + mx[k]][y + my[k]][k][9]
          ) {
            q[grid[x + mx[k]][y + my[k]]-1].push([x + mx[k], y + my[k], 9, k]);
            min[x + mx[k]][y + my[k]][k][9] =
              min[x][y][d][left] + grid[x + mx[k]][y + my[k]];
          }
        }
      }
    }
  }
}

// for (let i = 0; i < grid.length; ++i) {
//   let str = "";
//   for (let j = 0; j < grid[0].length; ++j) {
//     str +=
//       min[i][j]
//         .map((dira) => dira.slice(9))
//         .flat(5)
//         .reduce((acc, a) => Math.min(acc, a), Infinity) + " ";
//   }
//   // console.log(str);
// }

ans = Infinity;

// console.log(min);

for (let k = 0; k < 4; ++k) {
  ans = Math.min(ans, ...min[grid.length - 1][grid[0].length - 1][k]);
}

console.log(ans);
// fs.writeFileSync(
//   "out.txt",
//   fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
// );
