import fs from 'node:fs';

const inned = fs.readFileSync('input', 'utf-8').trim();

for (let i = 0; i < inned.length - 14; ++i) {
  if ([...new Set([...Array(14)].map((_, ine) => inned[i + ine]))].length == 14) {
    console.log(i+14);
    break;
  }
}
