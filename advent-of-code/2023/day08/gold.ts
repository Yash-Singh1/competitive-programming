import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

const seq = lines[0];
const left = new Map<string, string>(), right = new Map<string, string>();
let edges = ``;
lines.slice(2).forEach((line) => {
  const [leftv, rightv] = line
    .split(" = ")[1]
    .trim()
    .split(/,\s+/)
    .map((v) => v.trim())
    .map((v) => v.replaceAll(/\(|\)/g, ""));
  const op = line.split(" = ")[0].trim();
  left.set(op, leftv);
  right.set(op, rightv);
});

function evalp(startl: string) {
  for (let i = 0; i < seq.length; i++) {
    if (seq[i] === "L") {
      startl = left.get(startl)!;
    } else {
      startl = right.get(startl)!;
    }
  }
  return startl;
}

function gcd(a: number, b: number) {
  var R;
  while ((a % b) > 0)  {
    R = a % b;
    a = b;
    b = R;
  }
  return b;
}

function lcm(arr: number[]) {
  if (arr.length === 2) {
    return (arr[0] * arr[1]) / gcd(arr[0], arr[1]);
  } else if (arr.length === 1) {
    return arr[0];
  } else {
    return lcm([arr[0], lcm(arr.slice(1))]);
  }
}

const factors = new Set<number>();

for (const line of lines.slice(2)) {
  let keyv = line.split(" = ")[0].trim();
  if (keyv.endsWith("A")) {
    let curc = keyv;
    let count = 0;
    while (!curc.endsWith("Z")) {
      curc = evalp(curc);
      count += seq.length;
    }
    edges += `${keyv} ${curc} ${count}\n`;
    keyv = curc;
    factors.add(count);
    const done = new Set<string>();
    count = 0;
    do {
      curc = evalp(curc);
      if (done.has(curc)) {
        break;
      }
      count += seq.length;
      done.add(curc);
    } while ((!curc.endsWith("Z")))
    if (curc.endsWith("Z")) edges += `${keyv} ${curc} ${count}\n`;
  }
}

ans = lcm([...factors]);

console.log(ans);
fs.writeFileSync("edges.txt", edges);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
