import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(0, "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

for (const line of lines) {
  const [id, functionstr] = line.split(" -> ");
  let functions = functionstr.split(", ");
  for (const func of functions) {
    fs.writeFileSync('graph.txt', `${id} -> ${func}\n`, { flag: 'a' })
  }
  // return [id, functions];
}
