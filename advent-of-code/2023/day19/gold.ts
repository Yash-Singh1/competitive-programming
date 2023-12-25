import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n\n";

const input = fs.readFileSync(0, "utf-8");
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
        // fs.writeFileSync(
        //   "graph.txt",
        //   fs.readFileSync("graph.txt", "utf-8") + "\n" + `${name} ${rule.split(':')[1]}` + "\n"
        // );
        let [condition, result] = rule.split(":");
        return [condition, result];
      } else {
        // fs.writeFileSync(
        //   "graph.txt",
        //   fs.readFileSync("graph.txt", "utf-8") + "\n" + `${name} ${rule}` + "\n"
        // );
        return rule;
      }
    });
    return [name, rules2];
  })
);

// function evaluateCondition(condition: string, values: Record<string, string>) {
//   condition = condition.replaceAll(/\s+/g, "");
//   let [ref, val] = condition.split(/[<>]/);
//   let op = condition[ref.length];
//   let refVal = values[ref];
//   console.log(ref, refVal, val, op);
//   if (op == "<") {
//     return refVal < Number(val);
//   } else if (op == ">") {
//     return refVal > Number(val);
//   } else {
//     throw new Error("Invalid operator");
//   }
// }

let defreq = {
  minx: 1,
  maxx: 4000,
  minm: 1,
  maxm: 4000,
  mina: 1,
  maxa: 4000,
  mins: 1,
  maxs: 4000,
};

// let q: [string, typeof defreq][] = [];
// for (const [key, value] of Object.entries(funcs)) {
//   if (value.includes("A")) {
//     q.push([key, defreq]);
//   }
// }

const movereqs = new Map<string, [string, typeof defreq][]>();

function addToMap(key: string, value: [string, typeof defreq]) {
  // console.log(key, value);
  let cur = movereqs.get(key);
  if (cur) {
    movereqs.set(key, [...cur, value]);
  } else {
    movereqs.set(key, [value]);
  }
}

let qq = [];

qq.push(["in", defreq]);

for (const [key, value] of Object.entries(funcs)) {
  let curreqs = {...defreq};
  // console.log(key);
  for (const rule of value) {
    if (Array.isArray(rule)) {
      let condition = rule[0];
      condition = condition.replaceAll(/\s+/g, "");
      let [ref, val] = condition.split(/[<>]/) as [
        "x" | "m" | "a" | "s",
        string
      ];
      let op = condition[ref.length];
      let newreqs = { ...curreqs };
      if (op === ">") {
        newreqs["min" + ref] = Math.max(newreqs["min" + ref], Number(val) + 1);
      } else {
        newreqs["max" + ref] = Math.min(newreqs["max" + ref], Number(val) - 1);
      }
      if (newreqs["min" + ref] <= newreqs["max" + ref]) {
        addToMap(key, [rule[1], newreqs]);
      }
      if (op === ">") {
        curreqs["max" + ref] = Math.min(curreqs["max" + ref], Number(val));
      } else {
        curreqs["min" + ref] = Math.max(curreqs["min" + ref], Number(val));
      }
      if (curreqs["min" + ref] > curreqs["max" + ref]) {
        break;
      }
    } else {
      // movereqs.set([key, rule].join(','), curreqs);
      addToMap(key, [rule, curreqs]);
    }
  }
}

function mergeReqs(req1: typeof defreq, req2: typeof defreq) {
  let newreqs = { ...req1 };
  for (const [key, value] of Object.entries(req2)) {
    if (key.startsWith("min")) {
      newreqs[key] = Math.max(newreqs[key], value);
    } else {
      newreqs[key] = Math.min(newreqs[key], value);
    }
  }
  return newreqs;
}

let q: [string, typeof defreq][] = [["in", defreq]];
let reqs = new Map<string, (typeof defreq)[]>();

function addToMap2(key: string, value: typeof defreq) {
  let cur = reqs.get(key);
  if (cur) {
    reqs.set(key, [...cur, value]);
  } else {
    reqs.set(key, [value]);
  }
}
let visited = new Set<string>();
while (q.length > 0) {
  let [cur, reqi] = q.pop()!;
  if (visited.has(cur)) {
    continue;
  }
  visited.add(cur);
  let curreqs = movereqs.get(cur);
  for (const [key, value] of curreqs ?? []) {
    addToMap2(key, mergeReqs(reqi, value));
    q.push([key, mergeReqs(reqi, value)]);
  }
}

// console.log(reqs.get("A")!.length);

ans = reqs.get("A")!.reduce((acc, a) => {
  let ansi = 1;
  for (const variable of ["x", "m", "a", "s"]) {
    if (a["min" + variable] > a["max" + variable]) {
      return acc;
    }
    ansi *= a["max" + variable] - a["min" + variable] + 1;
  }
  acc += ansi;
  return acc;
}, 0);

// lines[1].split("\n").forEach((line) => {
//   line = line.replaceAll("=", ":");
//   line = line.replaceAll(/(\W)(\w+)(\W)/g, "$1\"$2\"$3");
//   let values = JSON.parse(line);
//   let curFn = "in";
//   while (!["A", "R"].includes(curFn)) {
//     let rules = funcs[curFn];
//     for (let rule of rules) {
//       if (Array.isArray(rule)) {
//         if (evaluateCondition(rule[0], values)) {
//           curFn = rule[1];
//           break;
//         }
//       } else {
//         curFn = rule;
//         break;
//       }
//     }
//     console.log(curFn);
//   }
//   if (curFn == "A") {
//     ans += Object.values(values).reduce(
//       (acc: number, a: number) => acc + a,
//       0
//     ) as number;
//   }
// });

console.log(ans);
// fs.writeFileSync(
//   "out.txt",
//   fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
// );
