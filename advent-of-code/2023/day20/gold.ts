import assert from "node:assert";
import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

let broadcaster = [
  lines[0].split(" -> ")[0],
  lines[0].split(" -> ")[1].split(", "),
];
lines = lines.slice(1);

let inputs: Record<string, string[] | undefined> = {};

function addToInput(id: string, value: string) {
  if (inputs[id] === undefined) {
    inputs[id] = [];
  }
  inputs[id]!.push(value);
}

let flipflopstate: Record<string, boolean> = {};

let flipflop = Object.fromEntries(
  lines
    .filter((line) => line.startsWith("%"))
    .map((line) => {
      line = line.slice(1);
      const [id, functionstr] = line.split(" -> ");
      let functions = functionstr.split(", ");
      flipflopstate[id] = false;
      for (const func of functions) {
        addToInput(func, id);
      }
      return [id, functions];
    })
);

let conjunctionstate: Record<string, Record<string, "low" | "high">> = {};

let conjunction = Object.fromEntries(
  lines
    .filter((line) => line.startsWith("&"))
    .map((line) => {
      line = line.slice(1);
      const [id, functionstr] = line.split(" -> ");
      let functions = functionstr.split(", ");
      conjunctionstate[id] = {};
      for (const inn of inputs[id] ?? []) {
        conjunctionstate[id][inn] = "low";
      }
      return [id, functions];
    })
);

let pulsessent = {
  low: 0,
  high: 0,
} as { low: number; high: number };

// function run(state: string, pulse: 'low' | 'high' = 'low', sender: string) {
// }

let rxreached = false;
let i = 0;

const seen = new Set<string>();
let q = [["rx", "low"]];
while (q.length > 0) {
  let [state, pulse] = q.shift()!;
  // if (state === "rx" && pulse === "low") {
  //   rxreached = true;
  //   break;
  // }
  const desc = state in flipflop ? 'flipflop' : 'conjunction';
  if (desc === undefined) {
    continue;
  }
  for (const inn of inputs[state] ?? []) {
    if (desc === 'flipflop') {
      
    }
  }
}

// run('broadcaster', 'low', 'broadcaster');

ans = i;

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
