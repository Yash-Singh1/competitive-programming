const fs = require('fs');
const path = require('path');

let autocompletions = [];

fs.readFileSync(path.join(__dirname, 'input'), 'utf-8')
  .split('\n')
  .filter((line) => {
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
            failed = true;
          } else {
            stack.pop();
          }
          break;
        case ']':
          if (stack[stack.length - 1] !== 'square') {
            failed = true;
          } else {
            stack.pop();
          }
          break;
        case '}':
          if (stack[stack.length - 1] !== 'curly') {
            failed = true;
          } else {
            stack.pop();
          }
          break;
        case '>':
          if (stack[stack.length - 1] !== 'angle') {
            failed = true;
          } else {
            stack.pop();
          }
          break;
      }
    });
    if (failed) return false;
    return true;
  })
  .forEach((line) => {
    let stack = [];
    line.split('').forEach((char) => {
      switch (char) {
        case '{':
          stack.push('}');
          break;
        case '[':
          stack.push(']');
          break;
        case '(':
          stack.push(')');
          break;
        case '<':
          stack.push('>');
          break;
        case ')':
          stack.pop();
          break;
        case ']':
          stack.pop();
          break;
        case '}':
          stack.pop();
          break;
        case '>':
          stack.pop();
          break;
      }
    });
    autocompletions.push(stack.reverse().join(''));
  });

const autocompletionBracketScore = {
  ')': 1,
  ']': 2,
  '}': 3,
  '>': 4,
};

autocompletions = autocompletions
  .map((autocompletion) => autocompletion.split('').reduce((a, b) => 5 * a + autocompletionBracketScore[b], 0))
  .sort((a, b) => a - b);

console.log(autocompletions[Math.floor(autocompletions.length / 2)]);
