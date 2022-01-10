const fs = require('fs');
const path = require('path');

let lowPointValue = 0;

fs.readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .map((line) => line.split('').map((point) => +point))
  .forEach((row, rowIndex, heightMap) => {
    row.forEach((point, pointIndex) => {
      let above = true,
        below = true,
        right = true,
        left = true;

      if (rowIndex === 0) {
        above = false;
      } else if (rowIndex === heightMap.length - 1) {
        below = false;
      }
      if (pointIndex === 0) {
        left = false;
      } else if (pointIndex === row.length - 1) {
        right = false;
      }

      if (above && heightMap[rowIndex - 1][pointIndex] <= point) {
        return;
      }
      if (below && heightMap[rowIndex + 1][pointIndex] <= point) {
        return;
      }
      if (right && row[pointIndex + 1] <= point) {
        return;
      }
      if (left && row[pointIndex - 1] <= point) {
        return;
      }

      lowPointValue += point + 1;
    });
  });

console.log(lowPointValue);
