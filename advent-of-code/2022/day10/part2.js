import fs from 'node:fs';
import process from 'node:process';

const inned = fs.readFileSync('input', 'utf-8').trim();

const steps = inned.split('\n');

let cycle = 0;
let x = 1;
let str = '';
const check = () => {
  if ([Math.max(x-1, 0), x, Math.min(39, x+1)].includes(cycle%40)) {
    str += ('#');
  } else {
    str += ('.');
  }
  if (cycle % 40 == 0) {
    str += ('\n');
  }
}
for (const step of steps) {
  if (step == 'noop') {
    check();
    ++cycle;
  } else {
    for (let i = 0; i < 2; ++i) {
      check();
      ++cycle;
    }
    x += parseInt(step.split(' ')[1], 10)
  }
}

console.log(str);
