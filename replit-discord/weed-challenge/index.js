const data = require('./puzzle.json');

let currentDay = 0;
let grid = data.filter((datapoint) => datapoint.day === 0).map((datapoint) => ({ ...datapoint, stage: 0, substageDaysCompleted: 1, ungrownDays: 0 }));
const totalDays = 200;
let naturallyDied = 0;

for (currentDay; currentDay < totalDays; currentDay++) {
  grid = grid
    .map((square) => {
      if (square.stage === 0) {
        if (
          grid
            .filter((anotherSquare) => anotherSquare.x === square.x && anotherSquare.y === square.y)
            .find(
              (anotherSquare) =>
                [square.x - 1, square.x + 1].includes(anotherSquare.x) ||
                [square.y - 1, square.y + 1].includes(anotherSquare.y) ||
                ([square.x - 1, square.x + 1].includes(anotherSquare.x) && [square.y - 1, square.y, square.y + 1].includes(anotherSquare.y))
            )
        ) {
          return { ...square, ungrownDays: square.ungrownDays + 1 };
        }
        square.ungrownDays = 0;
        if (square.substageDaysCompleted === 4) {
          return { ...square, stage: 1, substageDaysCompleted: 0 };
        } else {
          return { ...square, substageDaysCompleted: square.substageDaysCompleted + 1 };
        }
      } else if (square.stage === 1) {
        if (
          grid
            .filter((anotherSquare) => anotherSquare.x === square.x && anotherSquare.y === square.y)
            .find((anotherSquare) => [square.y - 1, square.y + 1].includes(anotherSquare.y))
        ) {
          return { ...square, ungrownDays: square.ungrownDays + 1 };
        }
        square.ungrownDays = 0;
        if (square.substageDaysCompleted === 3) {
          return { ...square, stage: 2, substageDaysCompleted: 0 };
        } else {
          return { ...square, substageDaysCompleted: square.substageDaysCompleted + 1 };
        }
      } else if (square.stage === 2) {
        if (
          grid
            .filter((anotherSquare) => anotherSquare.x === square.x && anotherSquare.y === square.y)
            .find((anotherSquare) => [square.x - 1, square.x + 1].includes(anotherSquare.x))
        ) {
          return { ...square, ungrownDays: square.ungrownDays + 1 };
        }
        square.ungrownDays = 0;
        if (square.substageDaysCompleted === 3) {
          return { ...square, stage: 3, substageDaysCompleted: 0 };
        } else {
          return { ...square, substageDaysCompleted: square.substageDaysCompleted + 1 };
        }
      } else if (square.stage === 3) {
        if (square.substageDaysCompleted === 3) {
          return;
        } else {
          return { ...square, substageDaysCompleted: square.substageDaysCompleted + 1 };
        }
      }
    })
    .filter((square) => {
      if (typeof square === 'undefined') {
        naturallyDied++;
        return false;
      } else if (square.ungrownDays === 3) {
        return false;
      }
      return true;
    });
  grid = grid.concat(
    data
      .filter((datapoint) => datapoint.day === currentDay + 1 && !grid.find((square) => square.x === datapoint.x && square.y === datapoint.y))
      .map((datapoint) => ({ ...datapoint, stage: 0, substageDaysCompleted: 1, ungrownDays: 0 }))
  );
}

console.log(naturallyDied);
