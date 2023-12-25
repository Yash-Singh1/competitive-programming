import fs from "node:fs";

const DELIM = "\n\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

lines.forEach((line) => {
  let rows = line.split("\n").map((row) => row.split(""));
  let hashes = rows.map((row) => {
    return row
      .map((a, idx) => (a === "#" ? 2 ** idx : 0))
      .reduce((a, b) => a + b, 0);
  });

  function findMirror() {
    for (let i = 1; i < hashes.length; i++) {
      let above = hashes.slice(0, i).reverse();
      let below = hashes.slice(i);
      above = above.slice(0, below.length);
      below = below.slice(0, above.length);

      let diff = 0;
      let fail = false;
      for (let j = 0; j < above.length; j++) {
        if (above[j] !== below[j]) {
          if (diff) {
            fail = true;
            break;
          }
          let xor = above[j] ^ below[j];
          if ((xor & (xor - 1)) === 0) {
            diff = 1;
          } else {
            fail = true;
            break;
          }
        }
      }
      if (!fail && diff >= 1) {
        return i;
      }
    }
    return 0;
  }

  let rowv = findMirror() * 100;
  if (rowv) {
    ans += rowv;
  } else {
    rows = rows[0].map((_, colIndex) => rows.map((row) => row[colIndex]));
    hashes = rows.map((row) => {
      return row
        .map((a, idx) => (a === "#" ? 2 ** idx : 0))
        .reduce((a, b) => a + b, 0);
    });
    ans += findMirror();
  }
});

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
