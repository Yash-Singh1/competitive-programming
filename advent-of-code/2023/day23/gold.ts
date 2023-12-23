import assert, { fail } from "node:assert";
import fs from "node:fs";
import { MaxPriorityQueue } from "@datastructures-js/priority-queue";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

let grid = lines.map((line) => line.split(""));

// let q: [number, number, number, Set<number>, boolean][] = [];
// const q = new MaxPriorityQueue<[number, number, number, Set<number>, boolean]>(
//   (a) => a[0]
// );

// q.push([0, 0, 1, new Set([1]), false]);

// for (let i = 0; i < grid.length; ++i) {
//   for (let j = 0; j < grid[i].length; ++j) {
//     q.push([0, i, j, new Set([i * 1000 + j])]);
//   }
// }

let dirs = [
  [0, 1],
  [0, -1],
  [1, 0],
  [-1, 0],
];

let sloped = {
  ">": 0,
  "<": 1,
  v: 2,
  "^": 3,
};

const vis = new Set<string>();

let q: [number, number, number, Set<number>, number][] = [];
let aroundgoodie = new Set<number>();
for (let i = 1; i < grid.length - 1; ++i) {
  for (let j = 1; j < grid[i].length - 1; ++j) {
    if (grid[i][j] === "#") continue;
    // console.log("--");
    let aroundgood = 0;
    for (let k = 0; k < 4; ++k) {
      let [dx, dy] = dirs[k];
      let nx = i + dx;
      let ny = j + dy;
      if (grid[nx][ny] !== "#") {
        // console.log(nx, ny, i, dx, dy);
        ++aroundgood;
      }
    }
    if (aroundgood > 2) {
      // console.log(i, j, aroundgood);
      q.push([
        i,
        j,
        0,
        new Set([i * (grid.length + 1) + j]),
        i * (grid.length + 1) + j,
      ]);
      aroundgoodie.add(i * (grid.length + 1) + j);
    }
  }
}

q.push([0, 1, 0, new Set([1]), 1]);
q.push([
  grid.length - 1,
  grid[0].length - 2,
  0,
  new Set([(grid.length - 1) * (grid.length + 1) + grid[0].length - 2]),
  (grid.length - 1) * (grid.length + 1) + grid[0].length - 2,
]);

aroundgoodie.add(0 * (grid.length + 1) + 1);
aroundgoodie.add((grid.length - 1) * (grid.length + 1) + grid[0].length - 2);

// for (let i = 0; i < grid.length; ++i) {
//   for (let j = 0; j < grid[i].length; ++j) {
//     process.stdout.write(
//       aroundgoodie.has(i * (grid.length + 1) + j)
//         ? ("000" + (i * (grid.length + 1) + j)).slice(-4)
//         : grid[i][j].repeat(4)
//     );
//   }
//   process.stdout.write("\n");
// }

// console.log(aroundgoodie);

const edges: Record<number, [number, number][]> = {};

while (q.length) {
  let [x, y, l, _visited, original] = q.shift()!;

  for (let i = 0; i < 4; ++i) {
    let visited = new Set(_visited);
    let nx = x + dirs[i][0];
    let ny = y + dirs[i][1];
    if (nx < 0 || nx >= grid.length || ny < 0 || ny >= grid[0].length) {
      continue;
    }
    if (grid[nx][ny] === "#") {
      continue;
    }

    let key = nx * (grid.length + 1) + ny;
    if (visited.has(key)) {
      continue;
    }

    visited.add(key);
    if (aroundgoodie.has(key)) {
      if (!edges[original]) {
        edges[original] = [];
      }
      edges[original].push([nx * (grid.length + 1) + ny, l + 1]);
      break;
    } else {
      q.push([nx, ny, l + 1, visited, original]);
    }
  }
}

// for (const egel of Object.entries(edges)) {
//   for (const [x, y] of egel[1]) {
//     console.log(egel[0], x, y);
//   }
// }

let q2 = new MaxPriorityQueue<[number, Set<number>, number]>((s) => s[0]);
q2.push([0, new Set([1]), 1]);
let dists: Record<string, number> = {};
dists[1] = 0;
while (q2.isEmpty() === false) {
  let [l, vis, x] = (q2.pop());
  // console.log(l);
  for (const [nx, li] of edges[x]) {
    if (nx === (grid.length - 1) * (grid.length + 1) + grid[0].length - 2) {
      ans = Math.max(ans, l + li)
    }
    assert(li < 1000);
    let vis2 = new Set(vis);
    const key = [nx, [...vis].join(":")].join(",");
    if (!vis2.has(nx)) {
      // if (nx === (grid.length - 1) * (grid.length+1) + grid[0].length - 2) {
      //   console.log(l + li, li, l, [...pe, li]);
      //   console.log(vis2, vis2.size);
      // }
      vis2.add(nx);
      dists[nx] = l + li;
      q2.push([dists[nx], vis2, nx]);
    }
  }
}

// console.log(aroundgoodie.size)

console.log(dists[(grid.length - 1) * (grid.length+1) + grid[0].length - 2]);

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
