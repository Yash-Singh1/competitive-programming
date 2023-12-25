import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

const funcs = Object.fromEntries(
  lines[0].split("\n").map((line) => {
    let [name, rules] = line.split("{");
    rules = rules.slice(0, -1);
    let ruleVals = rules.split(",");
    let rules2 = ruleVals.map((rule) => {
      if (rule.includes(":")) {
        let [condition, result] = rule.split(":");
        return [condition, result];
      } else {
        return rule;
      }
    });
    return [name, rules2];
  })
);

function evaluateCondition(condition: string, values: Record<string, string>) {
  condition = condition.replaceAll(/\s+/g, "");
  let [ref, val] = condition.split(/[<>]/);
  let op = condition[ref.length];
  let refVal = values[ref];
  console.log(ref, refVal, val, op)
  if (op == "<") {
    return refVal < Number(val);
  } else if (op == ">") {
    return refVal > Number(val);
  } else {
    throw new Error("Invalid operator");
  }
}

lines[1].split("\n").forEach((line) => {
  line = line.replaceAll("=", ":");
  line = line.replaceAll(/(\W)(\w+)(\W)/g, "$1\"$2\"$3");
  let values = JSON.parse(line);
  let curFn = "in";
  while (!["A", "R"].includes(curFn)) {
    let rules = funcs[curFn];
    for (let rule of rules) {
      if (Array.isArray(rule)) {
        if (evaluateCondition(rule[0], values)) {
          curFn = rule[1];
          break;
        }
      } else {
        curFn = rule;
        break;
      }
    }
    console.log(curFn);
  }
  if (curFn == "A") {
    ans += Object.values(values).reduce(
      (acc: number, a: number) => acc + a,
      0
    ) as number;
  }
});

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
