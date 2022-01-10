const fs = require('fs');
const path = require('path');

let content = fs
  .readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .map((line) => line.split('').map((point) => +point));
let distance = Object.defineProperty(
  Object.fromEntries(
    [...Array(content.length).keys()].reduce((allVertexes, x) => {
      allVertexes.push(...[...Array(content[0].length).keys()].map((key) => [`${x},${key}`, Infinity]));
      return allVertexes;
    }, [])
  ),
  '0,0',
  { value: 0 }
);
let vertexesUnacconted = Object.keys(distance);

function extractMin() {
  let min = [null, Infinity];
  Object.entries(distance).forEach(([vertex, distance], vertexPointIndex) => {
    if (vertexesUnacconted.includes(vertex) && distance < min[1]) {
      min[0] = vertex;
      min[1] = distance;
    }
  });
  if (min[0] === null) {
    min[0] = content.length - 1 + ',' + (content[0].length - 1);
  }
  vertexesUnacconted = vertexesUnacconted.filter((vertex) => vertex !== min[0]);
  return min[0];
}

while (vertexesUnacconted.length > 0) {
  let looking = extractMin();
  const lookingSplit = looking.split(',').map((lookingScalar) => +lookingScalar);
  [
    ...(lookingSplit[0] + 1 !== content.length ? [[lookingSplit[0] + 1, lookingSplit[1]]] : []),
    ...(lookingSplit[1] + 1 !== content[0].length ? [[lookingSplit[0], lookingSplit[1] + 1]] : []),
  ].forEach((newPoint) => {
    if (distance[newPoint.join(',')] > distance[looking] + content[newPoint[0]][newPoint[1]]) {
      distance[newPoint.join(',')] = distance[looking] + content[newPoint[0]][newPoint[1]];
    }
  });
}

console.log(distance[`${content.length - 1},${content[0].length - 1}`]);
