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
    line = line.trim();
    lines[linei] = line;
    // console.log("rowi");
    const rlines = line.split("\n");
    let diffed = false;
    for (let i = 1; i < rlines.length; ++i) {
      if (clean && origsets[linei].has(i*1000)) continue;
      // console.log(i);
      let abv = i;
      let b4 = rlines.slice(0, abv);
      let starte = 0;
      let after = rlines.slice(abv, rlines.length);
      if (b4.length > after.length) {
        starte += b4.length - after.length;
        b4 = b4.slice(b4.length - after.length, b4.length);
        // console.log(b4.length);
      } else if (b4.length < after.length) {
        after = after.slice(0, b4.length);
      }
      after = after.reverse();
      // // console.log(b4, after)
      let b4s = b4.join("\n");
      let afters = after.join("\n");
      let diff = 0;
      let b4id = 0;
      let newc = "";
      for (let j = 0; j < b4s.length; ++j) {
        if (b4s[j] !== afters[j] && diff === 0) {
          diff = j + 1;
          b4id = rlines.slice(0, starte).join("\n").length + j + 1;
          newc = afters[j];
        } else if (b4s[j] !== afters[j]) {
          diff = -1;
        }
      }
      // console.log("d", diff, b4, after, starte, b4id - 1);
      if (clean && diff === 0) {
        // console.log("ayayayar", i);
        ans += 100 * i;
      } else if (!clean && diff > 0 && !diffed) {
        // console.log("ayayr", i);
        lines[linei] =
          line.slice(0, b4id - 1) + newc + line.slice(b4id, line.length);
        // return;
        diffed = true;
      } else if (!clean && diff === 0) {
        origsets[linei].add(i*1000);
      }
    }
    // console.log("coli");
    const rcols = [];
    for (let i = 0; i < rlines[0].length; ++i) {
      rcols.push("");
    }
    for (let i = 0; i < rlines.length; ++i) {
      for (let j = 0; j < rlines[i].length; ++j) {
        rcols[j] += rlines[i][j];
      }
    }
    for (let i = 1; i < rcols.length; ++i) {
      if (clean && origsets[linei].has(i)) continue;
      let abv = i;
      let starte = 0;
      let b4 = rcols.slice(0, abv);
      let after = rcols.slice(abv, rcols.length);
      if (b4.length > after.length) {
        starte += b4.length - after.length;
        b4 = b4.slice(b4.length - after.length, b4.length);
        // console.log(b4.length);
      } else if (b4.length < after.length) {
        after = after.slice(0, b4.length);
      }
      after = after.reverse();
      // console.log(b4, after);
      let b4s = b4.join("\n");
      let afters = after.join("\n");
      let diff = 0;
      let b4id = 0;
      let newc = "";
      for (let j = 0; j < b4s.length; ++j) {
        if (b4s[j] !== afters[j] && diff === 0) {
          diff = j + 1;
          // console.log(
          //   "foundd",
          //   j,
          //   rcols[0].length,
          //   rcols.length,
          //   rlines.length
          // );
          b4id =
            (j % (rcols[0].length + 1)) * (rcols.length + 1) +
            Math.floor(j / (rlines.length + 1)) +
            starte +
            1;
          newc = afters[j];
        } else if (b4s[j] !== afters[j]) {
          diff = -1;
        }
      }
      if (clean && diff === 0) {
        // console.log("ayayarac", i, linei);
        ans += i;
      } else if (!clean && diff > 0 && !diffed) {
        lines[linei] =
          line.slice(0, b4id - 1) + newc + line.slice(b4id, line.length);
        // console.log("ayay", i);
        // return;
        diffed = true;
      } else if (!clean && diff === 0) {
        origsets[linei].add(i);
      }
    }
  });
  clean = true;
  // console.log(lines.join("\n\n"));
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
