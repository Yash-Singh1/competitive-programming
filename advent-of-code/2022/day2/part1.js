import fs from 'node:fs';

const inned = fs.readFileSync('input', 'utf-8').trim();

const all = inned.split('\n');

let vgal = 0
all.forEach(sm => {
  sm = sm.split(' ');
  if (sm[0] == 'A') sm[0] = 1;
  if (sm[0] == 'B') sm[0] = 2;
  if (sm[0] == 'C') sm[0] = 3;
  if (sm[1] == 'X') sm[1] = 1;
  if (sm[1] == 'Y') sm[1] = 2;
  if (sm[1] == 'Z') sm[1] = 3;
  vgal += sm[1];
  if (sm[0] == sm[1]) vgal += 3;
  else if (sm[1] == 1 && sm[0] == 2) vgal += 0;
  else if (sm[1] == 2 && sm[0] == 3) vgal += 0;
  else if (sm[1] == 3 && sm[0] == 1) vgal += 0;
  else {
    vgal += 6;
  }
})

console.log(vgal)
