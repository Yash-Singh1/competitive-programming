module.exports = function binaryToDecimal(arr, opposite = false) {
  let decimal = 0;

  arr.forEach((bit, bitIndex) => {
    if (opposite) {
      if (bit === 0) {
        decimal += 2 ** (arr.length - bitIndex - 1);
      }
    } else {
      if (bit === 1) {
        decimal += 2 ** (arr.length - bitIndex - 1);
      }
    }
  });

  return decimal;
}
