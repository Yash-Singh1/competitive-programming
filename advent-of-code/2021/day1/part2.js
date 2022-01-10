const fs = require('fs');
const path = require('path');

let increased = 0;

let numbers = fs
  .readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .map((str) => +str);

let sumMap = {};

numbers.forEach((num, numIndex) => {
  if (numIndex >= 2) {
    sumMap[numIndex] = numbers[numIndex - 2] + numbers[numIndex - 1] + numbers[numIndex];
  }
});

Object.values(sumMap).forEach((_depth, depthIndex, depthArray) => {
  if (depthIndex !== 0) {
    if (depthArray[depthIndex - 1] < depthArray[depthIndex]) {
      increased++;
    }
  }
});

console.log(increased);
