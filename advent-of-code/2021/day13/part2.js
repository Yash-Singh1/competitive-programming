const fs = require('fs');
const path = require('path');

let content = fs.readFileSync(path.join(__dirname, 'input'), 'utf-8').split('\n\n');

let points = content[0].split('\n').map((pointLine) => pointLine.split(',').map((point) => +point));

content[1].split('\n').forEach((fold) => {
  fold = fold.slice('fold along '.length).split('=');
  fold[1] = +fold[1];

  switch (fold[0]) {
    case 'x':
      points = points.map((point) => [point[0] > fold[1] ? fold[1] - Math.abs(point[0] - fold[1]) : point[0], point[1]]);
      break;

    case 'y':
      points = points.map((point) => [point[0], point[1] <= fold[1] ? point[1] : fold[1] - Math.abs(point[1] - fold[1])]);
      break;
  }

  points = points.reduce((allPoints, point) => {
    if (!allPoints.find((allPoint) => allPoint[0] === point[0] && allPoint[1] === point[1])) {
      allPoints.push(point);
    }
    return allPoints;
  }, []);
});

let maxX = 0;
let maxY = 0;
points.forEach((point) => (point[0] > maxX ? (maxX = point[0]) : null));
points.forEach((point) => (point[1] > maxY ? (maxY = point[1]) : null));

let minX = Number(maxX);
let minY = Number(maxY);
points.forEach((point) => (point[0] < minX ? (minX = point[0]) : null));
points.forEach((point) => (point[1] < minY ? (minY = point[1]) : null));

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

range(minY, maxY).forEach((y) => {
  console.log();
  range(minX, maxX).forEach((x) => {
    if (points.find((point) => point[0] === x && point[1] === y)) {
      process.stdout.write('█');
    } else {
      process.stdout.write(' ');
    }
  });
});
console.log();
