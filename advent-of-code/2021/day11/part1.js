const fs = require('fs');
const path = require('path');

let flashes = 0;

let content = fs
  .readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .map((line) => line.split('').map((octopus) => +octopus));

for (let i = 0; i < 100; i++) {
  content.forEach((line, lineIndex) => {
    line.forEach((_octopus, octopusIndex) => {
      content[lineIndex][octopusIndex]++;
    });
  });

  let octopusesFlashed = [];

  let flashed = true;

  while (flashed) {
    flashed = false;
    content.forEach((line, lineIndex) => {
      line.forEach((octopus, octopusIndex) => {
        if (octopus > 9 && !octopusesFlashed.find((octopusFlashed) => octopusFlashed[0] === lineIndex && octopusFlashed[1] === octopusIndex)) {
          octopusesFlashed.push([lineIndex, octopusIndex]);
          flashes++;
          flashed = true;
        } else {
          return;
        }

        const right = octopusIndex !== line.length - 1;
        const left = octopusIndex !== 0;
        const up = lineIndex !== 0;
        const down = lineIndex !== content.length - 1;

        if (up) {
          if (right) {
            content[lineIndex - 1][octopusIndex + 1]++;
          }
          if (left) {
            content[lineIndex - 1][octopusIndex - 1]++;
          }
          content[lineIndex - 1][octopusIndex]++;
        }
        if (down) {
          if (right) {
            content[lineIndex + 1][octopusIndex + 1]++;
          }
          if (left) {
            content[lineIndex + 1][octopusIndex - 1]++;
          }
          content[lineIndex + 1][octopusIndex]++;
        }
        if (right) {
          content[lineIndex][octopusIndex + 1]++;
        }
        if (left) {
          content[lineIndex][octopusIndex - 1]++;
        }
      });
    });
  }

  octopusesFlashed.forEach(([lineIndex, octopusIndex]) => {
    content[lineIndex][octopusIndex] = 0;
  });
}

console.log(flashes);
