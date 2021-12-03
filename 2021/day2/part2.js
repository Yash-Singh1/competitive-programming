const fs = require('fs');
const path = require('path');

let horizontal = 0;
let depth = 0;
let aim = 0;

fs.readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .forEach((line) => {
    const lineDetails = line.split(/\s+/);
    lineDetails[1] = +lineDetails[1];
    switch (lineDetails[0]) {
      case 'forward':
        horizontal += lineDetails[1];
        depth += lineDetails[1] * aim;
        break;

      case 'up':
        aim -= lineDetails[1];
        break;

      case 'down':
        aim += lineDetails[1];
        break;
    }
  });

console.log(horizontal * depth);
