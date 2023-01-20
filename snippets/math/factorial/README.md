# Factorial

The factorial of an integer is the product of all positive integers less than or equal to that integer.

## Calculating

When using the factorial operation in combinatorics, the best way to calculate it is to probably memoize all possible answers. This is because we would be using the factorial operation several times and it would be best to calculate it once. Also, a recursive memoization approach would be too slow. You can see a snippet of how to do this in [factorial.cpp](./factorial.cpp). If we have to divide the factorial of a number at some point, for example in the combinations formula, it is also best to calculate the inverse of each factorial and memoize that too. In the snippet given, we are each lower inverse by that number because we are trying to remove a number from the denominator by multiplying by that number. When participating in hackable contests such as Codeforces and the modulus is $\gt10^9$, you should also use modular multiplication because that will prevent integer overflow.
