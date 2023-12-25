import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let cache = [1];
function factMemoize(key: number) {
  if (!cache[key]) {
    cache[key] = key * factMemoize(key - 1);
  } else {
    // just to demo cache:
    console.log("cache hit:", key);
  }
  return cache[key];
}

let ans = 0;

const mp = new Map<string, number>();

function getAns(groups: string, ssplate: string[], cur: number = 0) {
  if (mp.has([cur, groups, ssplate.join(",")].join(":"))) {
    return mp.get([cur, groups, ssplate.join(",")].join(":"))!;
  }
  if (groups.length === 0) {
    if (cur === 0 && ssplate.length === 0) {
      return 1;
    }
    if (ssplate.length === 1 && cur > 0 && cur.toString() === ssplate[0]) {
      return 1;
    }
    return 0;
  }
  let possibleMore = 0;
  for (const ch of groups) {
    if (ch === "#" || ch === "?") {
      possibleMore += 1;
    }
  }
  const sum = (arr: string[]) => arr.reduce((a, b) => a + parseInt(b), 0);
  if (cur > 0 && possibleMore + cur < sum(ssplate)) {
    return 0;
  }
  if (cur === 0 && possibleMore < sum(ssplate)) {
    return 0;
  }
  if (cur > 0 && ssplate.length === 0) {
    return 0;
  }
  let poss = 0;
  if (groups[0] == "." && cur > 0 && cur.toString() != ssplate[0]) {
    return 0;
  }
  if (groups[0] == "." && cur > 0) {
    poss += getAns(groups.slice(1), ssplate.slice(1), 0);
  }
  if (groups[0] == "?" && cur > 0 && cur.toString() == ssplate[0]) {
    poss += getAns(groups.slice(1), ssplate.slice(1), 0);
  }
  if ((groups[0] == "#" || groups[0] == "?") && cur > 0) {
    poss += getAns(groups.slice(1), ssplate, cur + 1);
  }
  if ((groups[0] == "?" || groups[0] == "#") && cur === 0) {
    poss += getAns(groups.slice(1), ssplate, 1);
  }
  if ((groups[0] == "?" || groups[0] == ".") && cur === 0) {
    poss += getAns(groups.slice(1), ssplate, 0);
  }
  mp.set([cur, groups, ssplate.join(",")].join(":"), poss);
  return poss;
  // let groupmatch = groups.split("");
  // if (groups[0] === ".") {
  //   if (ssplate === cur.toString() || ssplate.startsWith(cur + ",")) {
  //     // console.log(cur, groups, ssplate, 1);
  //     mp.set(
  //       [cur, groups, ssplate].join(":"),
  //       getAns(groups.slice(1), ssplate.slice(cur.toString().length + 1), 0)
  //     );
  //     return mp.get([cur, groups, ssplate].join(":"))!;
  //   } else if (!cur) {
  //     // console.log(cur, groups, ssplate, 1.5);
  //     mp.set(
  //       [cur, groups, ssplate].join(":"),
  //       getAns(groups.slice(1), ssplate, 0)
  //     );
  //     return mp.get([cur, groups, ssplate].join(":"))!;
  //   } else {
  //     // console.log(cur, groups, ssplate, 2);
  //     mp.set([cur, groups, ssplate].join(":"), 0);
  //     return mp.get([cur, groups, ssplate].join(":"))!;
  //   }
  // } else if (groups[0] === "#") {
  //   // if (parseInt(ssplate.split(",")[0], 10) < cur + 1) {
  //     // console.log(cur, groups, ssplate, 3);
  //     // mp.set([cur, groups, ssplate].join(":"), 0);
  //     // return 0;
  //   // } else {
  //     // console.log(cur, groups, ssplate, 4);
  //     mp.set(
  //       [cur, groups, ssplate].join(":"),
  //       getAns(groups.slice(1), ssplate, cur + 1)
  //     );
  //     return mp.get([cur, groups, ssplate].join(":"))!;
  //   // }
  // } else if (groups[0] === "?") {
  //   let minia = 0;
  //   if (ssplate === cur.toString() || ssplate.startsWith(cur + ",")) {
  //     // console.log(cur, groups, ssplate, 5);
  //     minia += getAns(
  //       groups.slice(1),
  //       ssplate.slice(cur.toString().length + 1),
  //       0
  //     )!;
  //   } else if (!cur) {
  //     // console.log(cur, groups, ssplate, 7);
  //     minia += getAns(groups.slice(1), ssplate, 0);
  //   }
  //   // {
  //   // console.log(cur, groups, ssplate, 6);
  //   minia += getAns(groups.slice(1), ssplate, cur + 1);  // # case
  //   // }

  //   mp.set([cur, groups, ssplate].join(":"), minia);
  //   return minia;
  // }
}

lines.forEach((line, idx) => {
  let groups = line.split(/\s+/)[0];
  let ssplate = line.split(/\s+/)[1];
  // if (!groups.startsWith(".")) {
  groups = (groups + "?")
    .repeat(5)
    .slice(0, -1)
    .replace(/^\.+/, "")
    .replace(/\.+$/, "");
  ssplate = (ssplate + ",").repeat(5).slice(0, -1);
  // }
  console.log(idx, getAns(groups, ssplate.split(",")));
  ans += getAns(groups, ssplate.split(","));
  // const qs = new Set<number>();
  // for (let i = 0; i < groups.length; i++) {
  //   if (groups[i] === "?") qs.add(i);
  // }
  // // if (!groups.includes("#") && !groups.includes(".")) {
  // //   ans +=
  // //     factMemoize(
  // //       ssplate.split(",").length * 2 +
  // //         1 +
  // //         (ssplate.split(",").reduce((a, b) => a + parseInt(b) + 1, 0) - 1)
  // //     ) /
  // //     factMemoize(
  // //       1 + (ssplate.split(",").reduce((a, b) => a + parseInt(b) + 1, 0) - 1)
  // //     );
  // //   return;
  // // }
  // // console.log(qs.size);
  // // ans = Math.max(ans, qs.size);
  // const qa = Array.from(qs);
  // let andiff = 0;
  // for (let i = 0; i < 1 << qs.size; ++i) {}
  // ans += groups.startsWith(".") ? Math.pow(andiff, 5) : andiff;
  // console.log(idx);
});

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
