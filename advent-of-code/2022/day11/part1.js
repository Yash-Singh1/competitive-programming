import fs from 'node:fs';

const inned = fs.readFileSync('input', 'utf-8').trim();

const monkeys = inned.split('\n\n')

let state = [...Array(monkeys.length)].map(() => []);
let ops = [...Array(monkeys.length)];
let div = [...Array(monkeys.length)].map(() => 0);
let thrown = [...Array(monkeys.length)].map(() => 0);
let inspections = [...Array(monkeys.length)].map(() => 0);

for (let i = 0; i < monkeys.length; i++) {
  state[i] = monkeys[i].split('\n')[1].split('Starting items: ')[1].split(', ').map(n => parseInt(n, 10));
  ops[i] = monkeys[i].split('\n')[2].split('Operation: new = ')[1];
  div[i] = parseInt(monkeys[i].split('\n')[3].split('Test: divisible by ')[1], 10);
  thrown[i] = [parseInt(monkeys[i].split('\n')[4].split('If true: throw to monkey ')[1], 10), parseInt(monkeys[i].split('\n')[5].split('If false: throw to monkey ')[1], 10)];
}

for (let i = 0; i < 20; ++i) {
  for (let j = 0; j < monkeys.length; j++) {
    for (let k = 0; k < state[j].length; k++) {
      state[j][k] = eval(`let old = ${state[j][k]}; ${ops[j]}`);
      state[j][k] /= 3;
      state[j][k] = Math.floor(state[j][k]);
      if (state[j][k] % div[j] === 0) {
        state[thrown[j][0]].push(state[j][k]);
      } else {
        state[thrown[j][1]].push(state[j][k]);
      }
      ++inspections[j];
    }
    state[j] = [];
  }
}

inspections = inspections.sort((a, b) => a - b)

console.log(inspections[inspections.length - 1] * inspections[inspections.length - 2]);
