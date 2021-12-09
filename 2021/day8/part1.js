const fs = require('fs');
const path = require('path');

console.log(
  fs
    .readFileSync(path.join(__dirname, 'input'), 'utf-8')
    .split('\n')
    .map((line) => line.split(' | ')[1].split(' '))
    .map((outputs) => outputs.filter((output) => [2, 4, 3, 7].includes(output.length)))
    .map((outputs) => outputs.length)
    .reduce((a, b) => a + b, 0)
);
