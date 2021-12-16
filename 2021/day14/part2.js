const fs = require('fs');
const path = require('path');

let content = fs.readFileSync(path.join(__dirname, 'input'), 'utf-8').split('\n\n');

let template = content[0];

const mappings = Object.fromEntries(content[1].split('\n').map((insertionRule) => insertionRule.split(' -> ')));

let pairFrequency = {};

template.split('').forEach((char, charIndex) => {
  if (charIndex === template.length - 1) return;
  const location = char + template[charIndex + 1];
  if (pairFrequency[location]) {
    pairFrequency[location]++;
  } else {
    pairFrequency[location] = 1;
  }
});

for (let i = 0; i < 40; i++) {
  const newPairFrequency = {};

  Object.entries(pairFrequency).forEach(([pair, frequency]) => {
    let startLoc = pair[0] + mappings[pair];
    let endLoc = mappings[pair] + pair[1];

    if (newPairFrequency[startLoc]) {
      newPairFrequency[startLoc] += frequency;
    } else {
      newPairFrequency[startLoc] = frequency;
    }
    if (newPairFrequency[endLoc]) {
      newPairFrequency[endLoc] += frequency;
    } else {
      newPairFrequency[endLoc] = frequency;
    }
  });

  pairFrequency = newPairFrequency;
}

const elementFrequencies = {};
Object.entries(pairFrequency).forEach(([element, frequency]) => {
  element = element[0];
  if (typeof elementFrequencies[element] !== 'undefined') {
    elementFrequencies[element] += frequency;
  } else {
    elementFrequencies[element] = frequency;
  }
});

elementFrequencies[template[template.length - 1]]++;

const frequencyValues = Object.values(elementFrequencies).sort((a, b) => a - b);

console.log(frequencyValues[frequencyValues.length - 1] - frequencyValues[0]);
