const fs = require("node:fs");
const { init } = require("z3-solver");

async function main() {
  const {
    Context, // High-level Z3Py-like API
  } = await init();
  const { Solver, Int, And } = new Context("main");

  const DELIM = "\n";

  const input = fs.readFileSync(process.argv[2], "utf-8");
  const trimmed = input.trim();
  let lines = trimmed.split(DELIM);

  let ans = 0;

  let hailstones = lines.map((line) => {
    const [pos, velocity] = line.split(" @ ");
    const [x, y, z] = pos.split(", ");
    const [vx, vy, vz] = velocity.split(", ");
    return [x, y, z, vx, vy, vz].map((n) => Number(n));
  });

  const [x, y, z, vx, vy, vz] = [
    Int.const("x"),
    Int.const("y"),
    Int.const("z"),
    Int.const("vx"),
    Int.const("vy"),
    Int.const("vz"),
  ];
  const t = hailstones.slice(0, 3).map((h, i) => Int.const(`t${i}`));
  const solver = new Solver();

  for (let i = 0; i < 3; ++i) {
    solver.add(
      x.add(t[i].mul(vx)).eq(t[i].mul(hailstones[i][3]).add(hailstones[i][0]))
    );
    solver.add(
      y.add(t[i].mul(vy)).eq(t[i].mul(hailstones[i][4]).add(hailstones[i][1]))
    );
    solver.add(
      z.add(t[i].mul(vz)).eq(t[i].mul(hailstones[i][5]).add(hailstones[i][2]))
    );
  }

  await solver.check();

  ans = solver.model().eval(x.add(y.add(z))).toString();

  console.log(ans);

  process.exit(0);
}

main();
