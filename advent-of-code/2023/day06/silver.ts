import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let sum = 1;

let [times, distance] = lines.map((line) =>
  line
    .split(":")[1]
    .trim()
    .split(/\s+/)
    .filter(Boolean)
    .map((num) => Number(num))
);

for (let i = 0; i < times.length; i++) {
  let sm = 0;
  for (let j = 0; j <= times[i]; ++j) {
    if (j * (times[i] - j) > distance[i]) {
      console.log(j);
      ++sm;
    }
  }
  console.log("---")
  console.log(sm)
  console.log("---")
  sum *= sm;
}

console.log(sum);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + sum + "\n"
);
