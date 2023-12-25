import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const lines = input.split(DELIM);
const trimmed = input.trim();

let sum = 0;

trimmed.split(DELIM).forEach((line, idx) => {
  line = line.split(': ')[1]
  const [win, have] = line.split('|').map(x => x.trim().split(' ').filter(Boolean).map(y => {
    return Number(y.trim())
  }));
  const s = new Set<number>();
  for (const num of win) {
    assert(!isNaN(num), );
    s.add(num);
  }
  let val = 0;
  for (const num of have) {
    assert(!isNaN(num), );
    if (s.has(num)) {
      if (val === 0) val = 1;
      else val *= 2;
    }
  }
  console.log(val);
  sum += val;
});

console.log(sum)
