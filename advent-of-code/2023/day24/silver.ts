import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

let hailstones = lines.map((line) => {
  const [pos, velocity] = line.split(" @ ");
  const [x, y] = pos.split(", ");
  const [vx, vy] = velocity.split(", ");
  return [x, y, vx, vy].map((n) => Number(n));
});

const mintest = hailstones.length > 100 ? 200000000000000 : 7;
const maxtest = hailstones.length > 100 ? 400000000000000 : 27;

let collisions: [number, number, number][] = [];

for (let i = 0; i < hailstones.length; ++i) {
  for (let j = i + 1; j < hailstones.length; ++j) {
    const [x1, y1, vx1, vy1] = hailstones[i];
    const [x2, y2, vx2, vy2] = hailstones[j];
    if (vy2 / vx2 - vy1 / vx1 === 0) continue;
    let t =
      (y1 - (vy1 / vx1) * x1 - (y2 - (vy2 / vx2) * x2)) /
      (vy2 / vx2 - vy1 / vx1);
    if ((t - x1) / vx1 < 0 || (t - x2) / vx2 < 0) {
      continue;
    }
    if (
      y1 - (vy1 / vx1) * x1 + t * (vy1 / vx1) < mintest ||
      y1 - (vy1 / vx1) * x1 + t * (vy1 / vx1) > maxtest
    )
      continue;
    if (t < mintest || t > maxtest) continue;
    collisions.push([t, i, j]);
  }
}

ans = collisions.length;

console.log(ans);
// fs.writeFileSync(
//   "out.txt",
//   fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
// );
