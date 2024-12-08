import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0n;

const lines = text.split("\n").filter(Boolean);

outer: for (const line of lines) {
  const [answer, ops] = line.split(":").map((s) => s.trim());
  const opsList = ops
    .split(" ")
    .map((s) => s.trim())
    .map((s) => BigInt(s));
  const ans = BigInt(answer);

  for (let i = 0; i <= Math.pow(2, opsList.length - 1) - 1; i++) {
    let num = opsList[0];
    let bitstring = i.toString(2).padStart(opsList.length - 1, "0");
    for (let j = 0; j < opsList.length - 1; j++) {
      if (bitstring[j] === "1") {
        num *= opsList[j + 1];
      } else if (bitstring[j] === "0") {
        num += opsList[j + 1];
      } else {
        num = BigInt(num.toString() + opsList[j + 1]);
      }
    }
    if (num === ans) {
      target += num;
      continue outer;
    }
  }

  for (let i = 0; i <= Math.pow(3, opsList.length - 1) - 1; i++) {
    let num = opsList[0];
    let bitstring = i.toString(3).padStart(opsList.length - 1, "0");
    for (let j = 0; j < opsList.length - 1; j++) {
      if (bitstring[j] === "1") {
        num *= opsList[j + 1];
      } else if (bitstring[j] === "0") {
        num += opsList[j + 1];
      } else {
        num = BigInt(num.toString() + opsList[j + 1]);
      }
    }
    if (num === ans) {
      target += num;
      continue outer;
    }
  }

  console.log(line);
}

console.log(target);
