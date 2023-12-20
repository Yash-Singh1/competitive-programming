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
  'low': 0,
  'high': 0
} as { 'low': number, 'high': number };

// function run(state: string, pulse: 'low' | 'high' = 'low', sender: string) {
// }

let rxreached = false;
let i = 1;

const seen = new Set<string>();

let needed = ['vm', 'vk', 'dn', 'kb'];

const mp = new Map<string, number>();
let lcme = Object.fromEntries(needed.map((x) => [x, []] as [string, number[]]));
let lcm2 = Object.fromEntries(needed.map((x) => [x, []] as [string, number[]]));
let lcmf = []

function gcd(a: number, b: number) {
  var R;
  while ((a % b) > 0)  {
    R = a % b;
    a = b;
    b = R;
  }
  return b;
}

function lcm(arr: number[]) {
  if (arr.length === 2) {
    return (arr[0] * arr[1]) / gcd(arr[0], arr[1]);
  } else if (arr.length === 1) {
    return arr[0];
  } else {
    return lcm([arr[0], lcm(arr.slice(1))]);
  }
}

for (; i < 100000000; ++i) {
  console.log(i)
  let q = [['broadcaster', 'low', 'broadcaster']];
  while (q.length > 0) {
    let [state, pulse, sender] = q.shift()!;
    if (state === 'sq' && pulse === 'high') {
      console.log(state, pulse, sender, i);
      if (!mp.has([state, sender].join(','))) {
        mp.set([state, sender].join(','), i);
      } else if (mp.get([state, sender].join(',')) !== -1) {
        // lcme[state].push(i - mp.get([state, sender].join(','))!);
        // lcm2[state].push(mp.get([state, sender].join(','))!);
        lcmf.push(i - mp.get([state, sender].join(','))!);
        if (lcmf.length === 4) {
          console.log(lcm(lcmf));
          process.exit(0);
        }
        mp.set([state, sender].join(','), -1);
      }
      // rxreached = true;
      // break;
    }
    if (state === "broadcaster") {
      ++pulsessent[pulse];
      for (const outbroad of broadcaster[1] ?? []) {
        // console.log(state + " -> " + outbroad + " " + pulse)
        ++pulsessent[pulse];
        q.push([outbroad, pulse, state]);
        // run(outbroad, pulse, state);
      }
    } else if (state in flipflop) {
      if (pulse === "low") {
        flipflopstate[state] = !flipflopstate[state];
        let runi = 'low' as 'low' | 'high';
        if (flipflopstate[state]) {
          runi = 'high';
        }
        for (const outflip of flipflop[state]) {
          // console.log(state + " -> " + outflip + " " + runi)
          ++pulsessent[runi];
          q.push([outflip, runi, state]);
          // run(outflip, runi, state);
        }
      }
    } else if (state in conjunction) {
      conjunctionstate[state][sender] = pulse;
      let runi = 'low' as 'low' | 'high';
      if (Object.values(conjunctionstate[state]).includes('low')) {
        runi = 'high';
      }
      for (const outconj of conjunction[state]) {
        // console.log(state + " -> " + outconj + " " + runi)
        ++pulsessent[runi];
        q.push([outconj, runi, state]);
        // run(outconj, runi, state);
      }
    }
  }
  // console.log(Object.values(conjunctionstate['kk']), Object.values(conjunctionstate['vt']), Object.values(conjunctionstate['xr']), Object.values(conjunctionstate['fv']));
}

console.log(lcme, lcm2)

ans = lcm(lcme[needed[0]]);
let ppl = Object.values(Object.fromEntries(needed.map((x) => [x, inputs[x]] as [string, number]))).flat();
console.log(ppl.length, [...new Set(ppl)].length);
assert(ppl.length === [...new Set(ppl)].length);

// run('broadcaster', 'low', 'broadcaster');

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
