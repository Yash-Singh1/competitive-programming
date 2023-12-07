import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync("in.txt", "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 1;



console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
