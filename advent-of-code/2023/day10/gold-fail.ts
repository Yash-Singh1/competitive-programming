import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let start = lines[0];
let grid = lines.slice(1).map((line) => line.split(""));
let startpos = [0, 0] as [number, number];
for (let i = 0; i < grid.length; ++i) {
  for (let j = 0; j < grid[i].length; ++j) {
    if (grid[i][j] === "S") {
      startpos = [i, j];
      grid[i][j] = start;
    }
  }
}

let distance = lines.slice(1).map((line) => line.split("").map(() => -1));

let q: [number, number][] = [startpos];
let my = [0, 0, 1, -1];
let mx = [1, -1, 0, 0];
let pipemp: Record<string, number[]> = {
  "|": [0, 1],
  "-": [2, 3],
  L: [1, 2],
  J: [1, 3],
  "7": [0, 3],
  F: [0, 2],
};

distance[startpos[0]][startpos[1]] = 0;

while (q.length > 0) {
  let [x, y] = q.pop()!;
  let curval = grid[x][y];
  for (let i = 0; i < 4; ++i) {
    let nx = x + mx[i];
    let ny = y + my[i];
    // console.log(
    //   i,
    //   pipemp[curval].includes(i),
    //   [nx, ny],
    //   curval
    // );
    if (!pipemp[curval].includes(i)) continue;
    if (
      nx >= 0 &&
      nx < grid.length &&
      ny >= 0 &&
      ny < grid[nx].length &&
      grid[nx][ny] !== "." &&
      (distance[x][y] + 1 < distance[nx][ny] || distance[nx][ny] === -1)
    ) {
      distance[nx][ny] = distance[x][y] + 1;
      q.push([nx, ny]);
    }
  }
}

let marked = distance.map((line) => line.map(() => false));

for (let i = 0; i < distance.length; ++i) {
  if (distance[i][0] === -1) marked[i][0] = true;
  if (distance[i][distance[i].length - 1] === -1)
    marked[i][distance[i].length - 1] = true;
}

for (let i = 0; i < distance[0].length; ++i) {
  if (distance[0][i] === -1) marked[0][i] = true;
  if (distance[distance.length - 1][i] === -1)
    marked[distance.length - 1][i] = true;
}

for (let i = 0; i < distance.length; ++i) {
  console.log(distance[i].map((dd) => dd.toString()).join(" "));
}

// for (let i = 0; i < distance.length; ++i) {
//   for (let j = 0; j < distance[i].length; ++j) {
//     if (distance[i][j] === -1) continue;
//     for (let k = 0; k < 4; ++k) {
//       let nx = i + mx[k];
//       let ny = j + my[k];
//       if (
//         nx >= 0 &&
//         nx < distance.length &&
//         ny >= 0 &&
//         ny < distance[nx].length &&
//         distance[nx][ny] === -1 &&
//         !marked[nx][ny]
//       ) {
//         q.push([nx, ny]);
//       }
//     }
//   }
// }

for (let father = 0; father < 10; ++father) {
  q = [];
  for (let i = 0; i < distance.length; ++i) {
    for (let j = 0; j < distance[i].length; ++j) {
      if (marked[i][j]) q.push([i, j]);
    }
  }
  while (q.length > 0) {
    let [x, y] = q.pop()!;
    if (distance[x][y] !== -1) continue;
    marked[x][y] = true;
    for (let i = 0; i < 4; ++i) {
      let nx = x + mx[i];
      let ny = y + my[i];
      if (
        nx >= 0 &&
        nx < distance.length &&
        ny >= 0 &&
        ny < distance[nx].length &&
        distance[nx][ny] === -1 &&
        !marked[nx][ny]
      ) {
        q.push([nx, ny]);
      }
    }
  }

  // Cut through loops
  for (let i = 0; i < distance.length; ++i) {
    for (let j = 0; j < distance[i].length; ++j) {
      if (distance[i][j] === -1 && !marked[i][j]) {
        for (let k = 0; k < 4; ++k) {
          let nx = i + mx[k];
          let ny = j + my[k];
          // if (!pipemp[curval].includes(i)) continue;
          if (
            nx >= 0 &&
            nx < distance.length &&
            ny >= 0 &&
            ny < distance[nx].length &&
            distance[nx][ny] !== -1
          ) {
            let continueon = false;
            switch ([k, grid[nx][ny]].join(",")) {
              case "0,|":
              case "1,|":
              case "0,L":
              case "1,L":
              case "0,J":
              case "1,J":
              case "0,7":
              case "1,7":
              case "0,F":
              case "1,F":
                continueon = true;
                break;
              case "2,-":
              case "3,-":
              case "2,F":
              case "3,F":
              case "2,7":
              case "3,7":
              case "2,J":
              case "3,J":
              case "2,L":
              case "3,L":
                continueon = true;
                break;
            }
            if (continueon) {
              // console.log([i, j], k, [nx, ny], grid[nx][ny]);
              let nnx = nx,
                nny = ny;
              let rightblocked =
                k <= 1 && ["F", "L", "-"].includes(grid[nx][ny])
                  ? true
                  : k >= 2 && ["7", "F", "|"].includes(grid[nx][ny])
                  ? true
                  : false;
              let leftblocked =
                k <= 1 && ["J", "7", "-"].includes(grid[nx][ny])
                  ? true
                  : k >= 2 && ["L", "J", "|"].includes(grid[nx][ny])
                  ? true
                  : false;
              let success = false;
              while (true) {
                nx += mx[k];
                ny += my[k];
                if (
                  !(
                    nx >= 0 &&
                    nx < distance.length &&
                    ny >= 0 &&
                    ny < distance[nx].length
                  )
                ) {
                  // console.log("hehe0");
                  break;
                }
                rightblocked =
                  rightblocked ||
                  (k <= 1 && ["F", "L", "-"].includes(grid[nx][ny])
                    ? true
                    : k >= 2 && ["7", "F", "|"].includes(grid[nx][ny])
                    ? true
                    : false);
                leftblocked =
                  leftblocked ||
                  (k <= 1 && ["J", "7", "-"].includes(grid[nx][ny])
                    ? true
                    : k >= 2 && ["L", "J", "|"].includes(grid[nx][ny])
                    ? true
                    : false);
                if (rightblocked && leftblocked) {
                  // console.log("hehe0.5");
                  break;
                }
                // if (!leftblocked) {
                //   if (k <= 1) {
                //     if (["7", "J"].includes(grid[nx][ny])) {
                //       // console.log("hehe1");
                //       break;
                //     }
                //   } else {
                //     if (["L", "J"].includes(grid[nx][ny])) {
                //       // console.log("hehe2");
                //       break;
                //     }
                //   }
                // }
                // if (!rightblocked) {
                //   if (k <= 1) {
                //     if (["F", "L"].includes(grid[nx][ny])) {
                //       // console.log("hehe3");
                //       break;
                //     }
                //   } else {
                //     if (["F", "7"].includes(grid[nx][ny])) {
                //       // console.log("hehe4");
                //       break;
                //     }
                //   }
                // }
                // if (
                //   (k <= 1 && grid[nx][ny] === "-") ||
                //   (k >= 2 && grid[nx][ny] === "|")
                // ) {
                //   // console.log("hehe5");
                //   break;
                // }
                if (
                  marked[nx][ny] ||
                  (k <= 1 &&
                    ((ny > 0 && !leftblocked && marked[nx][ny - 1]) ||
                      (ny < distance[nx].length - 1 &&
                        !rightblocked &&
                        marked[nx][ny + 1]))) ||
                  (k >= 2 &&
                    ((nx > 0 && !leftblocked && marked[nx - 1][ny]) ||
                      (nx < distance.length - 1 &&
                        !rightblocked &&
                        marked[nx + 1][ny])))
                ) {
                  success = true;
                  break;
                }
              }
              if (success) {
                console.log(
                  success,
                  i,
                  j,
                  leftblocked,
                  rightblocked,
                  k,
                  nx,
                  ny
                );
                marked[i][j] = true;
                q.push([i, j]);
              }
            }
          }
        }
      }
    }
  }
}

for (let i = 0; i < distance.length; ++i) {
  for (let j = 0; j < distance[i].length; ++j) {
    if (distance[i][j] === -1 && !marked[i][j]) {
      console.log(i, j);
      ++ans;
    }
  }
}

for (let i = 0; i < marked.length; ++i) {
  console.log(marked[i].map((dd) => (dd ? 1 : 0)).join(" "));
}

console.log(distance[0].length, distance.length);

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
