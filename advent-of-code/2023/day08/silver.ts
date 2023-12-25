import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

const seq = lines[0];
const left = new Map<string, string>(), right = new Map<string, string>();
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

let curc = "AAA";
while (curc !== "ZZZ") {
  curc = evalp(curc);
  ans += seq.length;
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
