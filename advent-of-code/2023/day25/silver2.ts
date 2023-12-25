import fs from "node:fs";

const DELIM = "\n";

const input = fs.readFileSync(process.argv[2], "utf-8");
const trimmed = input.trim();
let lines = trimmed.split(DELIM);

let ans = 0;

let g: Record<string, Set<[string, number]>> = {};

const nodes = [];
let thise = 0;
let es = [];

for (const line of lines) {
  let [start, after] = line.split(": ");
  nodes.push(start);
  let to = after.split(" ");
  g[start] ??= new Set();
  for (const t of to) {
    g[start].add([t, thise]);
    es.push([start, t]);
    g[t] ??= new Set();
    g[t].add([start, thise++]);
    // e.push([start++, t]);
    // console.log([start, t].join(" -> "));
  }
}

let visited = new Set();
let fp = [];
let fd = [];
let fn: string;
let illegallist = new Set();

function dfs(node: string, path: number[], path2: string[], le?: number) {
  if (visited.has(node)) return;
  visited.add(node);
  if (typeof le === "number") path.push(le);
  path2.push(node);
  if (node === fn) {
    fp = path;
    fd = path2;
    return;
  }
  for (const v of g[node] ?? []) {
    if (illegallist.has(v[1])) continue;
    dfs(v[0], path, path2, v[1]);
    if (fp.length) return;
  }
}

const ft = new Map<number, number>();

function shuffleArray(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
}

// More optimized using BFS from all sources

shuffleArray(nodes);

for (let i = 0; i < nodes.length / (lines.length > 100 ? 10 : 1); ++i) {
  visited = new Set();
  let q = [[nodes[i], []]];
  while (q.length) {
    let [nnode, path] = q.shift()!;
    if (visited.has(nnode)) continue;
    visited.add(nnode);
    for (const preve of path) {
      ft.set(preve, (ft.get(preve) ?? 0) + 1);
    }
    for (const v of g[nnode] ?? []) {
      q.push([v[0], [...path, v[1]]]);
    }
  }
}

let fts: [number, number][] = [...ft.entries()].map((x) => [x[1], x[0]]);

fts.sort((a, b) => a[0] - b[0]);

illegallist.add(fts[fts.length - 1][1]);
illegallist.add(fts[fts.length - 2][1]);
illegallist.add(fts[fts.length - 3][1]);

visited = new Set();

dfs(nodes[0], [], []);

ans = visited.size * (Object.keys(g).length - visited.size);

console.log(ans);
fs.writeFileSync(
  "out.txt",
  fs.readFileSync("out.txt", "utf-8") + "\n" + ans + "\n"
);
