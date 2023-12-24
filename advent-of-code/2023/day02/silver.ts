import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync("in.txt", "utf-8");
const lines = input.split(DELIM);
const trimmed = input.trim();

let sum = 0;

const red = 12;
const green = 13;
const blue = 14;

const mx: Record<string,number> = {
  red,
  green,
  blue
}

trimmed.split(DELIM).forEach((line, idx) => {
  let linel = line
    .split(":")[1]
    .trim()
    .split(";")
    .map((str) => str.trim())
    .map((str) => {
      return str.split(",").map((val) => {
        return val.trim().split(" ").map(val2 => val2.trim());
      });
    });

  let valid = true;
  $: for (let i = 0; i < linel.length; ++i) {
    for (let j = 0; j < linel[i].length; ++j) {
      if (parseInt(linel[i][j][0], 10) > mx[linel[i][j][1]]) {
        valid = false;
        break $;
      }
    }
  }

  if (valid) sum += idx+1;
});

console.log(sum)
