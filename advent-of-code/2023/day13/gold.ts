import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n\n";

const input = fs.readFileSync("in.txt", "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;
let clean = false;

const origsets = lines.map(() => new Set<number>());

for (let k = 0; k < 2; ++k) {
  lines.forEach((line, linei) => {
    let rlines = line.split("\n");
    for (let i = 1; i < rlines.length; ++i) {
      
    }
  });
  clean = true;
  console.log(lines.join("\n\n"));
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  (fs.readFileSync("out.txt", "utf-8") + "\n" + ans).trim() + "\n"
);
