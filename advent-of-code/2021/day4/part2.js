const fs = require('fs');
const path = require('path');

let content = fs.readFileSync(path.join(__dirname, 'input'), 'utf-8').split('\n\n');

let draws = content[0].split(',').map((draw) => +draw);

let bingoBoards = content.slice(1).map((bingoBoardLines, bingoBoardIndex) => {
  return Object.defineProperty(
    bingoBoardLines.split('\n').map((bingoBoardLine) => {
      return bingoBoardLine
        .trim()
        .split(/\s+/)
        .map((bingoBoardPoint) => ({ drawn: false, number: +bingoBoardPoint }));
    }),
    'index',
    { value: bingoBoardIndex }
  );
});

function findLoser() {
  const result = bingoBoards.filter((bingoBoard) => {
    if (bingoBoard.find((bingoBoardLine) => bingoBoardLine.every((bingoBoardPoint) => bingoBoardPoint.drawn === true))) {
      return false;
    }
    for (const index of bingoBoard[0].keys()) {
      if (bingoBoard.every((bingoBoardLine) => bingoBoardLine[index].drawn === true)) {
        return false;
      }
    }
    return true;
  });

  if (result.length === 1) {
    findWinner()
    return result[0].index;
  }

  return false;
}

function findWinner() {
  const result = bingoBoards.filter((bingoBoard) => {
    if (bingoBoard.find((bingoBoardLine) => bingoBoardLine.every((bingoBoardPoint) => bingoBoardPoint.drawn === true))) {
      return true;
    }
    for (const index of bingoBoard[0].keys()) {
      if (bingoBoard.every((bingoBoardLine) => bingoBoardLine[index].drawn === true)) {
        return true;
      }
    }
    return false;
  });

  if (result.length === bingoBoards.length) {
    return true;
  }

  return false;
}

function drawNumber(number) {
  bingoBoards = bingoBoards.map((bingoBoard, bingoBoardIndex) =>
    Object.defineProperty(
      bingoBoard.map((bingoBoardLine) =>
        bingoBoardLine.map((bingoBoardPoint) => ({
          ...bingoBoardPoint,
          drawn: bingoBoardPoint.drawn === true ? true : bingoBoardPoint.number === number ? true : false,
        }))
      ),
      'index',
      { value: bingoBoardIndex }
    )
  );
}

let loserFound;

for (const draw of draws) {
  drawNumber(draw);
  if (loserFound) {
    const winnerFound = findWinner();
    if (winnerFound) {
      console.log(
        bingoBoards[loserFound]
          .flat()
          .filter((winningPoint) => winningPoint.drawn === false)
          .map((winningPoint) => winningPoint.number)
          .reduce((a, b) => a + b, 0) * draw
      );
      break;
    }
  } else {
    const loser = findLoser(bingoBoards);
    if (loser !== false) {
      loserFound = loser;
    }
  }
}
