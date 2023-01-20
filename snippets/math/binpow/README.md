# Binary Exponentiation

Binary exponentiation is a technique for calculating a number $a^b\mod{m}$ in $O(\log_2{b})$ time.

## Applications

Binary exponentiation has a number of applications:

- Large number computations without overflow
- Applying Fermat's Little Theorem to compute modular division
- Usage in combinatorics problems

## How it Works

Binary Exponentiation works by the Divide & Conquer approach. It takes advantage of bitwise operators to divide the exponent into powers of 2. Now, we have only $\log_2{b}$ of exponentiation we have to work with. We can make use of the smaller segments to calculate the value of larger segments, because each larger segment is just the previous segment squared:

![Explanation](explanation.png)

Since we have to calculate the $\log_2{b}$ segments, the time complexity is $O(\log_2{b})$, and the space complexity is $O(1)$, because we just need to store a few numbers. Since we are simply multiplying, we can continuously modulus our variables by the given modulus number. For modulus numbers $\gt10^9$, we have to use modular multiplication instead of regular multiplication, to prevent edge case overflow.

## Snippet

At [`binpow.cpp`](./binpow.cpp), you can find my implementation of binary exponentiation.

## Fermat's Little Theorem

Fermat's Little Theorem is a theorem for working with modular division. It states that if we aer working with $\mod p$ where $p$ is a prime number, there exists for each $a$ that is a part of $\mod p$, an inverse $a^-1$ such that $a\cdot a^{-1}\equiv 1\pmod{p}$, where $a^{-1}\equiv a^{p-2}\pmod{p}$. This can be useful for example when evaluating the combinatorics formula $\mod p$, because we can simply calculate the numerator $\mod p$ and then multiply that by the inverse of the denominator $\mod p$. That will give us the equivalent of calculating the whole thing $\mod p$. Binary exponentiation comes in handy in this case because $p$ can be very large, and we can use binary exponentiation to calculate the exponent efficiently.
