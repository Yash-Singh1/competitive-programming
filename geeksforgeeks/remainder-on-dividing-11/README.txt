This solution makes use of the classic technique for checking divisibility of 11.

Digit1 - Digit2 + Digit3 - Digit4 + Digit5 ...

However, the current implementation has a few flaws when it comes to this technique for negative numbers.

The correct solution would be to take advantage of the Addition Property of Modular Arithmetic.

(A + B) mod C = (A mod C + B mod C) mod C.

To use this we can store an integer for the answer and iterate over each number in the
string and add it to the current answer multiplied by 10 and run modulo 11 on that.
