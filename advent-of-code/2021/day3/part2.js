const fs = require('fs');
const path = require('path');
const binary2decimal = require('./binary2decimal');

let content = fs.readFileSync(path.join(__dirname, 'input'), 'utf-8').split('\n');
let oxygen = Array.from(content);
let co2 = Array.from(content);

let frequency;

function calculateFrequency(arr) {
  frequency = [...new Int8Array(content[0].length)].map(() => [0, 0]);

  arr.forEach((line) => {
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
}

let oxyCharIndex = 0;
while (oxygen.length > 1) {
  calculateFrequency(oxygen);
  oxygen = oxygen.filter((line) => {
    if (+line[oxyCharIndex] === frequency[oxyCharIndex]) {
      return true;
    }
    return false;
  });
  oxyCharIndex++;
}

let co2CharIndex = 0;

while (co2.length > 1) {
  calculateFrequency(co2);
  co2 = co2.filter((line) => {
    if (+line[co2CharIndex] !== frequency[co2CharIndex]) {
      return true;
    }
    return false;
  });
  co2CharIndex++;
}

console.log(binary2decimal([...oxygen[0]].map((num) => +num)) * binary2decimal([...co2[0]].map((num) => +num)));
