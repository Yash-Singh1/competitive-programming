const fs = require('fs');
const path = require('path');

let content = fs.readFileSync(path.join(__dirname, 'input'), 'utf-8').split('\n\n');

let template = content[0];

const mappings = content[1].split('\n').map((insertionRule) => insertionRule.split(' -> '));

for (let i = 0; i < 10; i++) {
  const insertionIndices = [];

  mappings.forEach((insertionRule) => {
    let lastIndex = -1;

    function insertIndices() {
      const foundIndex = template.indexOf(insertionRule[0], lastIndex + 1);
      if (foundIndex !== -1) {
        lastIndex = foundIndex;
        insertionIndices.push([foundIndex + 1, insertionRule[1]]);
        insertIndices();
      } else {
        return;
      }
    }

    insertIndices();
  });

  insertionIndices.sort((a, b) => a[0] - b[0]);

  let insertionIncreases = 0;
  insertionIndices.forEach(([insertionIndex, insertionString]) => {
    template = template.slice(0, insertionIndex + insertionIncreases) + insertionString + template.slice(insertionIndex + insertionIncreases);
    insertionIncreases++;
  });
}

const elementFrequencies = {};
template.split('').forEach((element) => {
  if (typeof elementFrequencies[element] !== 'undefined') {
    elementFrequencies[element]++;
  } else {
    elementFrequencies[element] = 1;
  }
});

const frequencyValues = Object.values(elementFrequencies).sort((a, b) => a - b);

console.log(frequencyValues[frequencyValues.length - 1] - frequencyValues[0]);
