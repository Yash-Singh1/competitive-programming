const fs = require('fs');
const path = require('path');

const caveMappings = {};

let content = fs
  .readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .forEach((map) => {
    const mappingSplit = map.split('-');
    if (caveMappings[mappingSplit[0]]) {
      caveMappings[mappingSplit[0]].push(mappingSplit[1]);
    } else {
      caveMappings[mappingSplit[0]] = [mappingSplit[1]];
    }
    if (caveMappings[mappingSplit[1]]) {
      caveMappings[mappingSplit[1]].push(mappingSplit[0]);
    } else {
      caveMappings[mappingSplit[1]] = [mappingSplit[0]];
    }
  });

let paths = caveMappings.start.map((startingPoint) => ['start', startingPoint]);

while (!paths.every((cavePath) => cavePath[cavePath.length - 1] === 'end')) {
  let ourPaths = [];
  paths.forEach((cavePath) => {
    if (cavePath[cavePath.length - 1] === 'end') {
      ourPaths.push(cavePath);
      return;
    }
    let pathsAddition = caveMappings[cavePath[cavePath.length - 1]].map((pathNextPoint) => [...cavePath, pathNextPoint]);
    pathsAddition = pathsAddition.filter((addedPath) => {
      if (addedPath[addedPath.length - 1] === 'start') {
        return false;
      }
      const smallPaths = [];
      addedPath.forEach((addedPathPoint) => {
        if (addedPathPoint.toLowerCase() === addedPathPoint && addedPathPoint !== 'start' && addedPathPoint !== 'end') {
          smallPaths.push(addedPathPoint);
        }
      });
      return smallPaths.length === new Set(smallPaths).size + 1 || smallPaths.length === new Set(smallPaths).size;
    });
    ourPaths = ourPaths.concat(pathsAddition);
  });
  paths = ourPaths;
  console.log(paths)
}

console.log(paths.map((cavePath) => cavePath.join(',')).length);
