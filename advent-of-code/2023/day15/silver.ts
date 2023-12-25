import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

lines[0].split(",").forEach((seq) => {
  if (seq) {
    let c = 0;
    for (const ch of seq) {
      c += ch.charCodeAt(0);
      c *= 17;
      c %= 256;
    }
    ans += c;
  }
});

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
