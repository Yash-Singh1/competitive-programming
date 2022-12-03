import fs from 'node:fs';

const inned = fs.readFileSync('input', 'utf-8').trim();

const input = inned.split('\n');
let abcs = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';

let priority = 0;
for (let i = 0; i < input.length; i += 3) {
  for (const char of input[i]) {
    if (input[i + 1].includes(char) && input[i + 2].includes(char)) {
      priority += abcs.indexOf(char) + 1;
      break;
    }
  }
}

console.log(priority);
