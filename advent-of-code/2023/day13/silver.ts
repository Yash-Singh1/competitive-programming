import fs from "node:fs";

const DELIM = "\n\n";

const input = fs.readFileSync(0, "utf-8");
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

      if (above.join(":") === below.join(":")) {
        return i;
      }
    }
    return 0;
  }

  ans += findMirror() * 100;
  rows = rows[0].map((_, colIndex) => rows.map((row) => row[colIndex]));
  hashes = rows.map((row) => {
    return row
      .map((a, idx) => (a === "#" ? 2 ** idx : 0))
      .reduce((a, b) => a + b, 0);
  });
  ans += findMirror();
});

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
