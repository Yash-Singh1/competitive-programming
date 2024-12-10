import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0n;

let line = [];
let spots = [];
let idx = 0;
for (let i = 0; i < text.length; i++) {
  spots.push(idx);
  if (i % 2 === 0) {
    for (let j = 0; j < Number(text[i]); j++) {
      line.push(i / 2);
    }
  } else {
    for (let j = 0; j < Number(text[i]); j++) {
      line.push(".");
    }
  }
  idx += Number(text[i]);
}

// console.log(line.join(""));

for (let d = 0; d < spots.length; d++) {
  let i = spots[d];
  if (spots.includes(i) && line[i] === ".") {
    let maxcount = 1;
    for (let j = i + 1; j < line.length; j++) {
      if (line[j] === "." && !spots.includes(j)) {
        maxcount++;
      } else break;
    }
    let curcount = 0;
    // console.log(maxcount, line.join(""));
    for (let j: number = line.length - 1; j > i + maxcount; j--) {
      if (line[j] != line[j - 1] && line[j] !== ".") {
        curcount++;
        if (curcount <= maxcount) {
          maxcount -= curcount;
          for (let k = i; k < i + curcount; k++) {
            line[k] = line[j];
          }
          for (let k = j; k < j + curcount; k++) {
            line[k] = ".";
          }
          if (maxcount === 0) {
            break;
          }
          i += curcount;
        }
        curcount = 0;
      } else {
        if (line[j] !== ".") curcount++;
      }
    }
  }
}

for (let i = 0; i < line.length; i++) {
  if (line[i] !== ".") {
    target += BigInt(line[i]) * BigInt(i);
  }
}

// console.log(line.join(""));

console.log(target);
