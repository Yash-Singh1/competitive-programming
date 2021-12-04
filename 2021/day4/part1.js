const fs = require('fs');
const path = require('path');

let content = fs.readFileSync(path.join(__dirname, 'input'), 'utf-8').split('\n\n');

let draws = content[0].split(',').map((draw) => +draw);

let bingoBoards = content.slice(1).map((bingoBoardLines) => {
  return bingoBoardLines.split('\n').map((bingoBoardLine) => {
    return bingoBoardLine
      .trim()
      .split(/\s+/)
      .map((bingoBoardPoint) => ({ drawn: false, number: +bingoBoardPoint }));
  });
});

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

  if (result.length > 0) {
    return result[0];
  }

  return false;
}

function drawNumber(number) {
  bingoBoards = bingoBoards.map((bingoBoard) =>
    bingoBoard.map((bingoBoardLine) =>
      bingoBoardLine.map((bingoBoardPoint) => ({
        ...bingoBoardPoint,
        drawn: bingoBoardPoint.drawn === true ? true : bingoBoardPoint.number === number ? true : false,
      }))
    )
  );
}

for (const draw of draws) {
  drawNumber(draw);
  const winner = findWinner(bingoBoards);
  if (winner) {
    console.log(
      winner
        .flat()
        .filter((winningPoint) => winningPoint.drawn === false)
        .map((winningPoint) => winningPoint.number)
        .reduce((a, b) => a + b, 0) * draw
    );
    break;
  }
}
