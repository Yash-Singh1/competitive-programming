import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let boxes: [string, number][][] = [];
for (let i = 0; i < 256; ++i) {
  boxes.push([]);
}

lines[0].split(",").forEach((seq) => {
  if (seq) {
    let chars = seq;
    let type = "minus";
    if (seq.includes("=")) {
      chars = seq.split("=")[0];
      type = "plus";
    } else {
      chars = seq.split("-")[0];
    }
    let c = 0;
    for (const ch of chars) {
      c += ch.charCodeAt(0);
      c *= 17;
      c %= 256;
    }
    let done = false;
    for (let i = 0; i < boxes[c].length; ++i) {
      if (boxes[c][i][0] === chars) {
        if (type === "plus") {
          boxes[c][i][1] = Number(seq.split("=")[1]);
          done = true;
        } else {
          boxes[c] = boxes[c].filter((x) => x[0] !== chars);
        }
        break;
      }
    }
    if (type === 'plus' && !done) {
      boxes[c].push([chars, Number(seq.split("=")[1])]);
    }
  }
});

for (let i = 0; i < 256; ++i) {
  for (let j = 0; j < boxes[i].length; ++j) {
    ans += (i+1) * (j+1) * boxes[i][j][1];
  }
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
