import fs from 'node:fs';

const inned = fs.readFileSync('input', 'utf-8').trim();

for (let i = 0; i < inned.length - 4; ++i) {
  if ([...new Set([inned[i], inned[i + 1], inned[i + 2], inned[i + 3]])].length == 4) {
    console.log(i+4);
    break;
  }
}
