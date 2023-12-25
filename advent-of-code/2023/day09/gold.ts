import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

lines.forEach((line) => {
  const dd = [line.split(/\s+/).filter(Boolean).map(Number)];
  console.log(dd);
  for (let i = 0; i < dd.length; ++i) {
    let nxt = [];
    let zero = true;
    for (let j = 0; j < dd[i].length - 1; ++j) {
      nxt.push(dd[i][j + 1] - dd[i][j]);
      if (nxt[nxt.length - 1] !== 0) {
        zero = false;
      }
    }
    dd.push(nxt);
    if (zero) {
      break;
    }
  }
  // console.log(dd)
  dd[dd.length - 1] = [0, ...dd[dd.length - 1]];
  for (let i = dd.length - 2; i >= 0; --i) {
    dd[i] = [dd[i][0] - dd[i + 1][0], ...dd[i]];
  }
  // console.log(dd)
  ans += dd[0][0];
});

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
