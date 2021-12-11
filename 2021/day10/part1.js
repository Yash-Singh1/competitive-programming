const fs = require('fs');
const path = require('path');

let scoring = 0;

fs.readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .filter((line) => {
    let depth = 0;
    line.split('').forEach((char) => {
      switch (char) {
        case '(':
        case '[':
        case '{':
        case '<':
          depth++;

        default:
          depth--;
      }
    });

    return depth !== 0;
  })
  .forEach((line) => {
    let stack = [];
    let failed = false;
    line.split('').forEach((char) => {
      if (failed) return;
      switch (char) {
        case '{':
          stack.push('curly');
          break;
        case '[':
          stack.push('square');
          break;
        case '(':
          stack.push('parenthesis');
          break;
        case '<':
          stack.push('angle');
          break;
        case ')':
          if (stack[stack.length - 1] !== 'parenthesis') {
            scoring += 3;
            failed = true;
          } else {
            stack.pop();
          }
          break;
        case ']':
          if (stack[stack.length - 1] !== 'square') {
            scoring += 57;
            failed = true;
          } else {
            stack.pop();
          }
          break;
        case '}':
          if (stack[stack.length - 1] !== 'curly') {
            scoring += 1197;
            failed = true;
          } else {
            stack.pop();
          }
          break;
        case '>':
          if (stack[stack.length - 1] !== 'angle') {
            scoring += 25137;
            failed = true;
          } else {
            stack.pop();
          }
          break;
      }
    });
  });

console.log(scoring);
