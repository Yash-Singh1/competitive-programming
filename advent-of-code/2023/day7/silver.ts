import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync("in.txt", "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

let cards = lines.map((line, idx) => {
  return [line.split(/\s+/)[0].split("").sort().join(""), idx, line.split(/\s+/)[0]] as const;
});
let bid = lines.map((line) => Number(line.split(/\s+/)[1]));

function freq(s: string) {
  const mp = new Map<string, number>();
  for (const c of s) {
    mp.set(c, (mp.get(c) ?? 0) + 1);
  }
  return [...mp.values()].sort().join(",");
}

function assign(freq: string) {
  switch (freq) {
    case "5":
      return 7;
    case "1,4":
      return 6;
    case "2,3":
      return 5;
    case "1,1,3":
      return 4;
    case "1,2,2":
      return 3;
    case "1,1,1,2":
      return 2;
    case "1,1,1,1,1":
      return 1;
  }
  return 0;
}

const order = "AKQJT98765432";

cards.sort((a, b) => {
  let diff = assign(freq(a[0])) - assign(freq(b[0]));
  if (diff) {
    return diff;
  } else {
    for (let i = 0; i < order.length; ++i) {
      if (order.indexOf(a[2][i]) < order.indexOf(b[2][i])) {
        return 1;
      } else if (a[2][i] != b[2][i]) {
        return -1;
      }
    }
    return 0;
  }
});

let i = 1;
for (const card of cards) {
  console.log(assign(freq(card[0])), card[2], bid[card[1]], i);
  ans += bid[card[1]] * i;
  ++i;
}

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
