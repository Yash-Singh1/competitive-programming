import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
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

  let mxv: Record<string,number> = {
    red: 0,
    green: 0,
    blue: 0
  };
  $: for (let i = 0; i < linel.length; ++i) {
    for (let j = 0; j < linel[i].length; ++j) {
      mxv[linel[i][j][1]] = Math.max(mxv[linel[i][j][1]], parseInt(linel[i][j][0], 10))
    }
  }

  sum += mxv.red * mxv.green * mxv.blue;
});

console.log(sum)
