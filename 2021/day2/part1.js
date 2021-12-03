const fs = require('fs');
const path = require('path');

let horizontal = 0;
let depth = 0;

fs.readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .forEach((line) => {
    const lineDetails = line.split(/\s+/);
    lineDetails[1] = +lineDetails[1];
    switch (lineDetails[0]) {
      case 'forward':
        horizontal += lineDetails[1];
        break;

      case 'up':
        depth -= lineDetails[1];
        break;

      case 'down':
        depth += lineDetails[1];
        break;
    }
  });

console.log(horizontal * depth);
