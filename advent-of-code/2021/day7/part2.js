const fs = require('fs');
const path = require('path');

let content = fs
  .readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split(',')
  .map((pos) => +pos);

let min = content[0];
let max = content[0];

content.forEach((pos) => {
  if (pos < min) {
    min = pos;
  } else if (pos > max) {
    max = pos;
  }
});

let allFuelEfficiency = [];

for (let endPosition = min; endPosition <= max; endPosition++) {
  let currentFuelEfficiency = 0;

  content.forEach((pos) => {
    let addedFuelEfficiency = Math.abs(pos - endPosition);
    currentFuelEfficiency += (addedFuelEfficiency * (addedFuelEfficiency + 1)) / 2;
  });

  allFuelEfficiency.push(currentFuelEfficiency);
}

let minFuelEfficiency = allFuelEfficiency[0];

allFuelEfficiency.find((fuelEfficiency) => {
  if (fuelEfficiency < minFuelEfficiency) {
    minFuelEfficiency = fuelEfficiency;
  }
});

console.log(minFuelEfficiency);
