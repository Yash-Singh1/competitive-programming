# Sieve of Eratosthenes

Calculates which numbers are prime and which are not.

## Count Divisors

We can count the divisors of a number in $O(\sqrt{n})$ time without precomputing any primes. This can be done given the fact that any divisor of $n$ less than $\sqrt{n}$ must have a corresponding divisor greater than $\sqrt{n}$. We can count all such divisors and add one for $\sqrt{n}$ if $n$ is a perfect square. You can find an implementation of this in [`count_divisors.cpp`](./count_divisors.cpp).

## Prime Factorization

We can also find the answer is $O(\log{x})$ time with $O(n\cdot(\ln{n}+\gamma))\approx O(n\log{n})$ preprocessing. We can find the prime factorization of a number and multiply the answer by the power of each prime plus one. We can find the prime factorization by continuously dividing by the largest prime that divides into a number, which can be found using the precomputation. You can find an implementation of this in [`prime_factorization.cpp`](./prime_factorization.cpp).

## Normal Sieve

The Normal Sieve is a method for finding the number of primes up till a maximum in $O(n\log{n})$ time. It works by keeping a boolean array storing whether each positive integer is prime or not. We then iterate from $[2, \sqrt{N}]$ and mark all the multiples of each prime encountered as composite. You can find a basic implementation in [`prime.cpp`](./prime.cpp). There are several optimizations that can be applied to this algorithm such as skipping 2s and 3s to make it 6x faster.

## Linear Sieve

There is a method to find prime numbers in linear time however it isn't well known. There is a Codeforces [blog article](https://codeforces.com/blog/entry/54090) on it. I am not aware of the proof of this algorithm, but you can find an implementation copied from the article in [`linear_sieve.cpp`](./linear_sieve.cpp).

## Segmented Sieve

Segmented Sieve allows us to find the primes in a range of numbers which has a large high bound, but the range is small. This can be done in $O(\sqrt{h}\log{\log{\sqrt{h}}}+(h-l)\log{\log{\sqrt{h}}})$ time given $h$ is the upper bound and $l$ is the lower bound. The algorithm has two parts to it:

1. Since we know that all factors of a number has a pair that is $\le{\sqrt{h}}$, we can use the normal sieve to find all primes up to $\sqrt{h}$.
2. We can now iterate over each prime calculated in the previous step and mark all multiples of it in the range $[l, h]$ as composite.

This is basically two sieve steps, one on $[1, \sqrt{h}]$ and another $[l, h]$.
