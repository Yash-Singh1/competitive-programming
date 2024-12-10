import * as fs from "node:fs";

const text = (await fs.readFileSync("./input.txt", "utf-8")).trim();

let target = 0n;

const diskmap = [];
let filemap = [];
console.log(text);
for (let i = 0; i < text.length; i++) {
  diskmap.push(BigInt(text[i]));
  if (i % 2 === 0) {
    filemap.push(BigInt(text[i]));
  }
}

// console.log(diskmap);

const newmap: [bigint, number][] = [];
let filemapmin = 0;
let unsettlingFilemap = new Set<number>();

for (let i = 0; i < diskmap.length; i++) {
  if (i % 2 === 0) {
    // console.log(diskmap[i], i / 2);
    if (diskmap[i] && !unsettlingFilemap.has(i / 2)) newmap.push([diskmap[i], i / 2]);
    filemapmin++;
  } else {
    // while (diskmap[i] && filemap.length - 1 >= filemapmin) {
    //   const sub = Math.min(filemap.at(-1)!, diskmap[i]);
    //   diskmap[i] -= sub;
    //   diskmap[(filemap.length - 1) * 2] -= sub;
    //   filemap[filemap.length - 1] -= sub;
    //   newmap.push([sub, filemap.length - 1]);
    //   if (filemap[filemap.length - 1] === 0) {
    //     filemap.pop();
    //   }
    // }
    console.log(i, filemapmin);
    for (let j = filemap.length - 1; j >= filemapmin; j--) {
      if (filemap[j] <= diskmap[i] && filemap[j] && !unsettlingFilemap.has(j)) {
        const sub = filemap[j] < diskmap[i] ? filemap[j] : diskmap[i];
        diskmap[i] -= sub;
        // diskmap[j * 2] -= sub;
        filemap[j] -= sub;
        unsettlingFilemap.add(j);
        newmap.push([sub, j]);
      }
      if (diskmap[i] === 0n) {
        break;
      }
    }
    if (diskmap[i] > 0) {
      newmap.push([diskmap[i], 0n]);
    }
  }
}

let position = 0n;

let line = "";

for (const [count, idx] of newmap) {
  console.log(position, count, idx);
  let sum = 0n;
  for (let i = position; i < BigInt(position) + count; i++) {
    sum += i;
    if (idx) line += idx;
    else line += ".";
  }
  target += sum * BigInt(idx);
  position += count;
}

console.log(line);

console.log(target);
