import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
const lines = trimmed.split(DELIM);

let ans = 0;

lines.forEach((line) => {
  const groups = line.split(/\s+/)[0];
  let ssplate = line.split(/\s+/)[1];
  const qs = new Set<number>();
  for (let i = 0; i < groups.length; i++) {
    if (groups[i] === "?") qs.add(i);
  }
  const qa = Array.from(qs);
  for (let i = 0; i < 1 << qs.size; ++i) {
    let groupmatch = groups.split("");
    for (let j = 0; j < qa.length; ++j) {
      if ((i >> j) & 1) groupmatch[qa[j]] = "#";
      else groupmatch[qa[j]] = ".";
    }
    let splat = groupmatch.join("").split(/\.+/);
    splat = splat.filter((x) => x !== "");
    if (ssplate === splat.map(s => s.length).join(",")) {
      ++ans;
    }
  }
});

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
