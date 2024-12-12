import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

let grid = text.split("\n").map((line) => line.split(""));

let regions = [...grid.map((line) => line.map((char) => -1))];  
let regionCount = 0;

console.log(grid, regions)

for (let i = 0; i < grid.length; i++) {
  for (let j = 0; j < grid[i].length; j++) {
    if (regions[i][j] === -1) {
      regions[i][j] = regionCount;
      let area = 0, perimeter = 0;
      let q = [{ x: i, y: j }];
      while (q.length > 0) {
        let { x, y } = q.shift()!;
        perimeter+= 4;
        area++;
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
      regionCount++;
      console.log(i, j, area, perimeter);
      target += area * perimeter;
    }
  }
}

for (let i = 0; i < grid.length; i++) {
  let line = ""
  grid[i].forEach((_, j) => {
    line += regions[i][j].toString().padStart(2, "0") + ",";
  });
  console.log(line);
}

console.log(target);
