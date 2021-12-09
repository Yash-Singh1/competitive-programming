const fs = require('fs');
const path = require('path');

let lowPoints = [];

const content = fs
  .readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .map((line) => line.split('').map((point) => +point));

function getAboveBelowLeftRight(rowIndex, pointIndex, row, heightMap) {
  let above = true,
    below = true,
    right = true,
    left = true;

  if (rowIndex === 0) {
    above = false;
  } else if (rowIndex === heightMap.length - 1) {
    below = false;
  }
  if (pointIndex === 0) {
    left = false;
  } else if (pointIndex === row.length - 1) {
    right = false;
  }

  return [above, below, right, left];
}

content.forEach((row, rowIndex, heightMap) => {
  row.forEach((point, pointIndex) => {
    const [above, below, right, left] = getAboveBelowLeftRight(rowIndex, pointIndex, row, heightMap);

    if (above && heightMap[rowIndex - 1][pointIndex] <= point) {
      return;
    }
    if (below && heightMap[rowIndex + 1][pointIndex] <= point) {
      return;
    }
    if (right && row[pointIndex + 1] <= point) {
      return;
    }
    if (left && row[pointIndex - 1] <= point) {
      return;
    }

    lowPoints.push([rowIndex, pointIndex]);
  });
});

let originalLowPointLength = 0;

while (lowPoints.length !== originalLowPointLength) {
  originalLowPointLength = Number(lowPoints.length);

  content.forEach((row, rowIndex, heightMap) => {
    row.forEach((point, pointIndex) => {
      if (lowPoints.find((lowPoint) => lowPoint[0] === rowIndex && lowPoint[1] === pointIndex) || point === 9) {
        return;
      }

      const [above, below, right, left] = getAboveBelowLeftRight(rowIndex, pointIndex, row, heightMap);

      if (
        above &&
        content[rowIndex - 1][pointIndex] < point &&
        lowPoints.find((lowPoint) => lowPoint[0] === rowIndex - 1 && lowPoint[1] === pointIndex)
      ) {
        lowPoints.push([rowIndex, pointIndex]);
      } else if (
        below &&
        content[rowIndex + 1][pointIndex] < point &&
        lowPoints.find((lowPoint) => lowPoint[0] === rowIndex + 1 && lowPoint[1] === pointIndex)
      ) {
        lowPoints.push([rowIndex, pointIndex]);
      } else if (
        right &&
        content[rowIndex][pointIndex + 1] < point &&
        lowPoints.find((lowPoint) => lowPoint[0] === rowIndex && lowPoint[1] === pointIndex + 1)
      ) {
        lowPoints.push([rowIndex, pointIndex]);
      } else if (
        left &&
        content[rowIndex][pointIndex - 1] < point &&
        lowPoints.find((lowPoint) => lowPoint[0] === rowIndex && lowPoint[1] === pointIndex - 1)
      ) {
        lowPoints.push([rowIndex, pointIndex]);
      }
    });
  });
}

let basins = [];

lowPoints.forEach((lowPoint) => {
  const basinFound = basins.findIndex((basin) =>
    basin.find(
      (existingLowPoint) =>
        (existingLowPoint[0] === lowPoint[0] && (existingLowPoint[1] + 1 === lowPoint[1] || existingLowPoint[1] - 1 === lowPoint[1])) ||
        (existingLowPoint[1] === lowPoint[1] && (existingLowPoint[0] + 1 === lowPoint[0] || existingLowPoint[0] - 1 === lowPoint[0]))
    )
  );

  if (basinFound === -1) {
    basins.push([lowPoint]);
  } else {
    basins[basinFound].push(lowPoint);
  }
});

console.log(
  basins
    .sort((basinA, basinB) => basinB.length - basinA.length)
    .map((basin) => basin.length)
    .slice(0, 3)
    .reduce((a, b) => a * b, 1)
);
