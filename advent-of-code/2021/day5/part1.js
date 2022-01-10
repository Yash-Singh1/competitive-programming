const fs = require('fs');
const path = require('path');

// Based on https://stackoverflow.com/a/69900650/13514657
const range = (from, to) => {
  if (from > to) {
    const inTheSideFrom = Number(from);
    const inTheSideTo = Number(to);
    to = inTheSideFrom;
    from = inTheSideTo;
  }
  return [...Array(to - from + 1)].map((_, i) => i + from);
};

let content = fs
  .readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .map((pipe) => pipe.split(' -> ').map((point) => point.split(',').map((pointPart) => +pointPart)))
  .filter((pipe) => pipe[0][0] === pipe[1][0] || pipe[0][1] === pipe[1][1])
  .map((pipe) =>
    pipe[0][0] === pipe[1][0]
      ? range(...pipe.map((point) => point[1])).map((yValue) => [pipe[0][0], yValue].join(','))
      : range(...pipe.map((point) => point[0])).map((xValue) => [xValue, pipe[0][1]].join(','))
  );

const repetition = {};

content.forEach((pipe) => {
  pipe.forEach((point) => {
    if (repetition[point]) {
      repetition[point]++;
    } else {
      repetition[point] = 1;
    }
  });
});

console.log(Object.values(repetition).filter((value) => value !== 1).length);
