import fs from 'node:fs';

const inned = fs.readFileSync('input', 'utf-8').trim();

const steps = inned.split('\n');

let cycle = 0;
let x = 1;
let ans = 0;
const check = () => {
  if ([20, 60, 100, 140, 180, 220].includes(cycle)) {
    ans += x * cycle;
  }
}
for (const step of steps) {
  if (step == 'noop') {
    ++cycle;
    check();
  } else {
    for (let i = 0; i < 2; ++i) {
      ++cycle;
      check();
    }
    x += parseInt(step.split(' ')[1], 10)
  }
}

console.log(ans);
