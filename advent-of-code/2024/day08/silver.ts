import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

const diskmap = [];
const filemap = [];
for (let i = 0; i < text.length; i++) {
  diskmap.push(Number(text[i]));
  if (i % 2 === 0) {
    filemap.push(Number(text[i]));
  }
}

const newmap = [];

for (let i = 0; i < diskmap.length; i++) {
  if (diskmap[i] % 2 === 0) {
    newmap.push([diskmap[i], i / 2]);
  } else {
    while (diskmap[i] && filemap.length) {
      const sub = Math.min(filemap.at(-1)!, diskmap[i]);
      diskmap[i] -= sub;
      filemap[filemap.length - 1] -= sub;
      newmap.push([sub, filemap.length - 1]);
      if (filemap[filemap.length - 1] === 0) {
        filemap.pop();
      }
    }
  }
}

let position = 0;

for (const [count, idx] of newmap) {
  target +=
    (((position + count) * (position + count + 1)) / 2 -
      ((position - 1) * position) / 2) *
    idx;
}

console.log(target);
