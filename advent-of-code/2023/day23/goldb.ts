import assert, { fail } from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

let grid = lines.map((line) => line.split(""));

let dirs = [
  [0, 1],
  [0, -1],
  [1, 0],
  [-1, 0],
];

let endKey = (grid.length - 1) * (grid.length + 1) + grid[0].length - 2;

let q: [number, number, number, Set<number>, number][] = [];
let aroundgoodie = new Set<number>();
let aroundgoodiemap: Record<number, number> = {};
for (let i = 1; i < grid.length - 1; ++i) {
  for (let j = 1; j < grid[i].length - 1; ++j) {
    if (grid[i][j] === "#") continue;
    let aroundgood = 0;
    for (let k = 0; k < 4; ++k) {
      let [dx, dy] = dirs[k];
      let nx = i + dx;
      let ny = j + dy;
      if (grid[nx][ny] !== "#") {
        ++aroundgood;
      }
    }
    if (aroundgood > 2) {
      q.push([
        i,
        j,
        0,
        new Set([i * (grid.length + 1) + j]),
        aroundgoodie.size + 1,
      ]);
      aroundgoodie.add(i * (grid.length + 1) + j);
      aroundgoodiemap[i * (grid.length + 1) + j] = aroundgoodie.size;
    }
  }
}

aroundgoodiemap[1] = 0;
q.push([0, 1, 0, new Set([1]), 0]);
q.push([
  grid.length - 1,
  grid[0].length - 2,
  0,
  new Set([endKey]),
  aroundgoodie.size + 1,
]);

aroundgoodie.add(1);
aroundgoodiemap[endKey] = aroundgoodie.size;
aroundgoodie.add(endKey);

const edges = new Array<[number, number][]>(aroundgoodie.size);

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
      edges[original].push([
        aroundgoodiemap[nx * (grid.length + 1) + ny],
        l + 1,
      ]);
      break;
    } else {
      q.push([nx, ny, l + 1, visited, original]);
    }
  }
}

let visited = new Array<boolean>(aroundgoodie.size);
for (let i = 0; i < aroundgoodie.size; ++i) {
  visited[i] = false;
}

function dfs(l: number, cur: number) {
  if (l > ans && visited[aroundgoodie.size-1]) {
    ans = l;
    return;
  }
  for (let [next, dist] of edges[cur]) {
    if (!visited[next]) {
      visited[next] = true;
      dfs(l + dist, next);
      visited[next] = false;
    }
  }
}
visited[0] = true;

dfs(0, 0);

console.log(ans);
