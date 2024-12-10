import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0;

const diskmap = [];
const filemap = [];
console.log(text);
for (let i = 0; i < text.length; i++) {
  diskmap.push(Number(text[i]));
  if (i % 2 === 0) {
    filemap.push(Number(text[i]));
  }
}

// console.log(diskmap);

const newmap = [];
let filemapmin = 0;

for (let i = 0; i < diskmap.length; i++) {
  if (i % 2 === 0) {
    console.log(diskmap[i], i / 2);
    if (diskmap[i]) newmap.push([diskmap[i], i / 2]);
    filemapmin++;
  } else {
    while (diskmap[i] && filemap.length - 1 >= filemapmin) {
      const sub = Math.min(filemap.at(-1)!, diskmap[i]);
      diskmap[i] -= sub;
      diskmap[(filemap.length - 1) * 2] -= sub;
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
  console.log(position, count, idx);
  let sum = 0;
  for (let i = position; i < position + count; i++) {
    sum += i;
  }
  target += sum * idx;
  position += count;
}

console.log(target);
