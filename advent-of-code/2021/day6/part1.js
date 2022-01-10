const fs = require('fs');
const path = require('path');

let content = fs
  .readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split(',')
  .map((timer) => +timer);

for (let i = 1; i <= 80; i++) {
  let add = 0;
  content = content.map((timer) => {
    if (timer === 0) {
      add++;
      timer = 6;
    } else {
      timer--;
    }
    return timer;
  });
  for (let addingIndex = 0; addingIndex < add; addingIndex++) {
    content.push(8);
  }
}

console.log(content.length);
