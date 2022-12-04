import fs from 'node:fs';

const inned = fs.readFileSync('input', 'utf-8').trim();

const lst = inned.split('\n');

let tot = 0;

lst.forEach(s => {
  s = s.split(',');
  s[0] = s[0].split('-');
  s[1] = s[1].split('-');
  s[0][0] = parseInt(s[0][0]);
  s[0][1] = parseInt(s[0][1]);
  s[1][0] = parseInt(s[1][0]);
  s[1][1] = parseInt(s[1][1]);
  if (s[0][0] <= s[1][0] && s[0][1] >= s[1][1]) tot++;
  else if (s[1][0] <= s[0][0] && s[1][1] >= s[0][1]) tot++;
})

console.log(tot)
