const fs = require('fs');
const path = require('path');

let content = fs
  .readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split(',')
  .map((timer) => +timer);

const timerRepetition = {};

for (let i = 1; i <= 8; i++) {
  timerRepetition[i] = 0;
}

content.forEach((timer) => {
  timerRepetition[timer]++;
});

for (let i = 1; i <= 256; i++) {
  let add = 0;
  Object.entries(timerRepetition).forEach((entry) => {
    if (entry[0] === '0') {
      timerRepetition[6] = entry[1];
      add = entry[1];
    } else if (entry[0] === '7') {
      timerRepetition[6] += entry[1];
    } else {
      timerRepetition[+entry[0] - 1] = entry[1];
    }
  });
  timerRepetition[8] = add;
}

console.log(Object.values(timerRepetition).reduce((a, b) => a + b, 0));
