const fs = require('fs');
const path = require('path');

let content = fs.readFileSync(path.join(__dirname, 'input'), 'utf-8').split('\n\n');

let points = content[0].split('\n').map((pointLine) => pointLine.split(',').map((point) => +point));

let fold = content[1].split('\n')[0].slice('fold along '.length).split('=');
fold[1] = +fold[1];

switch (fold[0]) {
  case 'x':
    points = points.map((point) => [point[0] > fold[1] ? fold[1] - Math.abs(point[0] - fold[1]) : point[0], point[1]]);
    break;

  case 'y':
    points = points.map((point) => [point[0], point[1] > fold[1] ? point[1] : fold[1] + Math.abs(point[1] - fold[1])]);
    break;
}

console.log(
  points.reduce((allPoints, point) => {
    if (!allPoints.find((allPoint) => allPoint[0] === point[0] && allPoint[1] === point[1])) {
      allPoints.push(point);
    }
    return allPoints;
  }, []).length
);
