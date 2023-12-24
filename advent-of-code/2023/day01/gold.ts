import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();

let sum = 0;

const nums = [
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine",
];

trimmed.split(DELIM).map((line) => {
  for (let i = 0; i < line.length; ++i) {
    let made = false;
    nums.forEach((num, idx) => {
      if (
        line.slice(i).indexOf(num) === 0 ||
        line.slice(i).indexOf((idx + 1).toString()) === 0
      ) {
        sum += (idx + 1) * 10;
        return (made = true);
      }
    });
    if (made) break;
  }
  for (let i = line.length - 1; i >= 0; --i) {
    let made = false;
    nums.forEach((num, idx) => {
      if (
        line.slice(i).indexOf(num) === 0 ||
        line.slice(i).indexOf((idx + 1).toString()) === 0
      ) {
        sum += idx + 1;
        return (made = true);
      }
    });
    if (made) break;
  }
});

console.log(sum);
