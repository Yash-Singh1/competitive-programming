const fs = require('fs');
const path = require('path');

const originalContent = fs.readFileSync(path.join(__dirname, 'input'), 'utf-8').split('\n');

let content = originalContent.map((line) => line.replace('| ', '').split(' ')).map((line) => line.sort((a, b) => a.length - b.length));

const cleanNumberMap = {
  2: ['c', 'f'],
  3: ['a', 'c', 'f'],
  4: ['b', 'c', 'd', 'f'],
  5: [
    ['a', 'c', 'd', 'e', 'g'],
    ['a', 'c', 'd', 'f', 'g'],
    ['a', 'b', 'd', 'f', 'g'],
  ],
  6: [
    ['a', 'b', 'd', 'e', 'f', 'g'],
    ['a', 'c', 'd', 'e', 'f', 'g'],
  ],
  7: ['a', 'b', 'c', 'd', 'e', 'f', 'g'],
};

const numberMap = Object.fromEntries(
  Object.entries(cleanNumberMap).map((entry) => [
    entry[0],
    Array.isArray(entry[1][0]) ? entry[1].reduce((accumalator, entryArray) => accumalator.concat(entryArray), []) : entry[1],
  ])
);

const signalStates = [];

content.forEach((outputs) => {
  let signalState = {};

  outputs
    .filter((output) => output.length < 5)
    .forEach((output) => {
      // signalState = Object.fromEntries(
      //   Object.entries(signalState).map((entry) => [
      //     entry[0],
      //     output.includes(entry[0]) ? entry[1] : entry[1].filter((possibleSignal) => !output.includes(possibleSignal)),
      //   ])
      // );
      const chars = output.split('');
      chars.forEach((char) => {
        if (!signalState[char]) {
          signalState[char] = [...new Set(numberMap[output.length])];
        } else {
          signalState[char] = numberMap[output.length].filter((existingChar) => signalState[char].includes(existingChar));
        }
      });
    });

  const unincludedChars = numberMap[7].filter((char) => !Object.values(signalState).some((existingChar) => existingChar.includes(char)));

  numberMap[7].forEach((char) => {
    if (!signalState[char]) {
      signalState[char] = unincludedChars;
    }
  });

  signalStates.push(signalState);
});

function signalStateCombinations(signalState) {
  const entries = Object.entries(signalState);
  if (entries.length === 0) {
    return [{}];
  }
  return [...entries[0][1].values()]
    .map((key) =>
      signalStateCombinations(Object.fromEntries(entries.slice(1))).map((signalStateCombination) => ({
        ...signalStateCombination,
        [entries[0][0]]: key,
      }))
    )
    .flat();
}

const outputNumbers = [];

const combinationToNumber = {
  abcefg: 0,
  cf: 1,
  acdeg: 2,
  acdfg: 3,
  bcdf: 4,
  abdfg: 5,
  abdefg: 6,
  acf: 7,
  abcdefg: 8,
  abcdfg: 9,
};

const validCombinations = Object.keys(combinationToNumber);

signalStates.forEach((signalState, signalIndex) => {
  let combinations = signalStateCombinations(signalState).filter(
    (combination) => Object.values(combination).length === new Set(Object.values(combination)).size
  );
  combinations = combinations.filter((combination) => {
    return content[signalIndex].every((word) =>
      validCombinations.includes(
        word
          .split('')
          .map((char) => combination[char])
          .sort()
          .join('')
      )
    );
  });
  outputNumbers.push(
    +originalContent[signalIndex]
      .split(' | ')[1]
      .split(' ')
      .map(
        (chars) =>
          combinationToNumber[
            chars
              .split('')
              .map((char) => combinations[0][char])
              .sort()
              .join('')
          ]
      )
      .join('')
  );
});

console.log(outputNumbers.reduce((a, b) => a + b, 0));
