import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

let grid = text.split("\n").map((line) => line.split(""));

let regions = [...grid.map((line) => line.map((char) => -1))];  
let regionCount = 0;

for (let i = 0; i < grid.length; i++) {
  for (let j = 0; j < grid[i].length; j++) {
    if (regions[i][j] === -1) {
      regions[i][j] = regionCount;
      let regionSet = new Set<string>();
      let area = 0, perimeter = 0;
      let q = [{ x: i, y: j }];
      while (q.length > 0) {
        let { x, y } = q.shift()!;
        perimeter += 4;
        area++;
        regionSet.add([x, y].join(","));
        for (let [dx, dy] of [[0, 1], [0, -1], [1, 0], [-1, 0]]) {
          let nx = x + dx;
          let ny = y + dy;
          if (nx >= 0 && nx < grid.length && ny >= 0 && ny < grid[0].length && grid[nx][ny] === grid[i][j]) {
            perimeter--;
            if (regions[nx][ny] === -1) {
              regions[nx][ny] = regionCount;
              q.push({ x: nx, y: ny });
            }
          }
        }
      }
      const exposedSet = new Set<string>();
      for (const regionCoord of regionSet) {
        const [x, y] = regionCoord.split(",").map((x) => parseInt(x)) as [number, number]; 
        for (let [dx, dy] of [[1, 0], [-1, 0], [0, 1], [0, -1]]) {
          if (!(x + dx >= 0 && x + dx < grid.length && y + dy >= 0 && y + dy < grid[0].length && grid[x + dx][y + dy] === grid[i][j])) {
            if (dx === 0) {
              let x1 = x - 1;
              while (x1 >= 0 && x1 < grid.length && grid[x1][y] === grid[i][j] && !(x1 + dx >= 0 && x1 + dx < grid.length && y + dy >= 0 && y + dy < grid[0].length && grid[x1 + dx][y + dy] === grid[i][j])) {
                x1--;
              }
              if (x1 < 0) x1 = 0;
              exposedSet.add([x1, y, dx, dy].join(","));
            }
            if (dy === 0) {
              let y1 = y - 1;
              while (y1 >= 0 && y1 < grid[0].length && grid[x][y1] === grid[i][j] && !(y1 + dy >= 0 && y1 + dy < grid[0].length && x + dx >= 0 && x + dx < grid.length && grid[x + dx][y1 + dy] === grid[i][j])) {
                y1--;
              }
              if (y1 < 0) y1 = 0;
              exposedSet.add([x, y1, dx, dy].join(","));
            }
          }
        }
      }
      regionCount++;
      target += exposedSet.size * area;
    }
  }
}

console.log(target);
