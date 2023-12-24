import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();

let sum = 0;

trimmed.split(DELIM).map((line) => {
  sum += parseInt(/\d/.exec(line)![0], 10) * 10;
  sum += parseInt(/\d/.exec(line.split("").reverse().join(""))![0], 10);
});

console.log(sum);
