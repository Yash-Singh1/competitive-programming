import fs from 'node:fs';

const inned = fs.readFileSync('input', 'utf-8').trim();

const lst = inned.split('\n');

let abcs = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';

let priority = 0;
lst.map(line => {
  let first = line.slice(0, line.length / 2);
  let second = line.slice(line.length / 2);
  for (const char of [...new Set(first)]) {
    if (second.includes(char)) {
      priority += abcs.indexOf(char) + 1;
    }
  }
})

console.log(priority);
