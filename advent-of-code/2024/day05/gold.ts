import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

const [rules, updates] = text.split("\n\n").map((s) => s.trim().split("\n"));

const matrices = [];
console.log(updates);
for (const update of updates) {
  const parts = update.split(",").map(Number);
  let outreal = true;
  for (const rule of rules) {
    const [a, b] = rule.split("|").map((s) => Number(s.trim()));
    let aFound = false;
    let bFound = false;
    let real = true;
    if (!parts.includes(a) || !parts.includes(b)) {
      continue;
    }
    console.log(a, b);
    for (const part of parts) {
      if (part === b && !aFound) {
        real = false;
        break;
      } else {
        bFound = true;
      }
      if (part === a) {
        aFound = true;
      }
    }
    if (!real) {
      outreal = false;
      break;
    }
  }
  if (outreal) {
    // target += parts[Math.floor(parts.length / 2)];
  } else {
    parts.sort((a, b) => {
      for (const rule of rules) {
        const [a2, b2] = rule.split("|").map((s) => Number(s.trim()));
        if (a === a2 && b === b2) {
          return -1;
        } else if (a === b2 && b === a2) {
          return 1;
        }
      }
      return 0;
    });
    target += parts[Math.floor(parts.length / 2)];
  }
}

console.log(target);
