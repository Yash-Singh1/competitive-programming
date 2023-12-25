import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let sum = 0;

const memo = new Map<string, number>();

function matches(line: string, i: number) {
  if (memo.has(line.split(': ')[0])) {
    return memo.get(line.split(': ')[0])!;
  }
  let cards = line.split(': ')[0];
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
      ++val;
    }
  }
  let rr = 1;
  for (let j = i+1; j <= i+val && j < lines.length; ++j) {
    rr += matches(lines[j], j);
  }
  memo.set(cards, rr);
  return rr;
}

trimmed.split(DELIM).map((x, i) => ({ x, i })).forEach(({x: line, i}) => {
  console.log(i, matches(line, i));
  sum += matches(line, i);
});

console.log(sum)
