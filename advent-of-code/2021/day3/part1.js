const fs = require('fs');
const path = require('path');

const content = fs.readFileSync(path.join(__dirname, 'input'), 'utf-8').split('\n');

let frequency = [...new Int8Array(content[0].length)].map(() => [0, 0]);

content.forEach((line) => {
  [...line].forEach((char, index) => {
    switch (char) {
      case '0':
        frequency[index][0]++;
        break;

      case '1':
        frequency[index][1]++;
        break;
    }
  });
});

frequency = frequency.map((frequencyPart) => (frequencyPart[0] > frequencyPart[1] ? 0 : 1));

const binaryToDecimal = require('./binary2decimal');

console.log(binaryToDecimal(frequency) * binaryToDecimal(frequency, true));
