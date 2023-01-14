# GCD

Greatest Common Divisor is the largest divisor that divides into two numbers.

## Prime Factorization Analogy

We can use an analogy of the GCD to the prime factorization of two numbers. Since we want the maximal divisor, but one that both numbers are divisible by, we can choose the minimum of each power on the prime factorization, e.g. for 6 and 8, we have:

$$
\begin{align*}
6 = 2^1 \cdot 3^1\\
8 = 2^3 \cdot 3^0\\
gcd(6, 8) = 2^{min(1, 3)} \cdot 3^{min(1, 0)} = 2
\end{align*}
$$

## Euclidean Algorithm

The Euclidean Algorithm defines the GCD as the following and can be proofed by using divisibility equations:

$$
gcd(a, b) =
\begin{cases}
a & b=0 \\
gcd(b, a\mod b) & b\neq 0
\end{cases}
$$

You can see the code for the Euclidean algorithm in the [gcd.cpp](./gcd.cpp) file (brought from USACO Guide).

## Builtin Functions

The C++ standard library has several builtin options for GCD, however these options have a few corner cases that don't exist when using a custom implementation.

## Time Complexity

The time complexity is $O(\log_2(ab))$ because taking the remainder at least halves the number. The upper bound for the Euclidean Algorithm is the Fibonacci numbers.

## GCD of Multiple Numbers

The GCD of multiple numbers can be calculated by progressively taking the GCD:

$$
gcd(a_1, a_2, ..., a_n) = gcd(a_1, gcd(a_2, gcd(...gcd(a_{n-1}, a_n)...)))
$$

## LCM

The LCM of a number is defined by the following:

$$
lcm(a, b) = \frac{a \cdot b}{gcd(a, b)}
$$
