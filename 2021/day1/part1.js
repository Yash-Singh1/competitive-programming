const fs = require('fs');
const path = require('path');

let increased = 0;

fs.readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .forEach((_depth, depthIndex, depthArray) => {
    if (depthIndex !== 0) {
      if (+depthArray[depthIndex - 1] < +depthArray[depthIndex]) {
        increased++;
      }
    }
  });

console.log(increased);
