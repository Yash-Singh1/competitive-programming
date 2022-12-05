import fs from 'node:fs';

const inned = fs.readFileSync('input', 'utf-8').trimEnd();

const parts = inned.split('\n\n');

const slen = parts[0].split('\n')[parts[0].split('\n').length - 1].trim().split(' ').length;

const stacks = [...Array(slen)].map(() => []);

let j = 0;
for (const part of parts[0].split('\n')) {
  if (j == parts[0].split('\n').length - 1) {
    break;
  } else {
    // let pos = 0;
    for (let i = 0; i < part.length; i += 4) {
      if (part[i] == ' ') {
        continue;
      } else {
        stacks[i / 4].unshift(part[i+1]);
      }
    }
  }
  ++j;
}

// console.debug(stacks)
for (const ln of parts[1].split('\n')) {
  let [_, c, frome, toe] = ln.match(/move (\d+) from (\d+) to (\d+)/);
  [c, frome, toe] = [c, frome, toe].map(Number);
  stacks[toe-1] = stacks[toe-1].concat(stacks[frome-1].slice(stacks[frome-1].length - c));
  for (let i = 0; i < c; i++) {
    stacks[frome-1].pop();
  }
  // console.debug(stacks)
}

console.log(stacks.map(stack => stack[stack.length-1]).join(''))
