# Rolling Hash

The polynomial rolling hash function is a method of hashing a string in linear time.

## How It Works

The function works by simply having a polynomial with the base being the size of the alphabet and the exponent being the index of the character. This essentially gives us a base-$k$ number where $k$ is the size of the alphabet in the case. For example, if we are working with the English Alphabet and we are to hash `blah`, then the polynomial will look like:

$$
2\cdot 26^0 + 12\cdot 26^1 + 1\cdot 26^2 + 8\cdot 26^3
$$

Notice how the coefficients are the position of the character in the alphabet. However, the problem with this is that the hash of a string can quickly get really large. A string with 14 characters already overflows the limits for `long long` in C++. The solution to this is to compute the hash modulo some number. This gives the possibility of hash collision, however if we choose a large enough modulo number, we can reduce the probability of collision.

## Precompute Substrings

Several string hashing problems require us to compute the hash of a substring. We can do this in linear time by precomputing the hash for every prefix, then we can use something similar to prefix sums to find the hash of a substring. To remove the extra coefficients, we can divide the hash by the power of the base up till that prefix. The problem with this approach however, is that we have to use binary exponentiation to compute the modular inverse of the power of the base, which can be very slow with large moduli. Another approach is to use suffix string hashing.

## Suffix String Hashing

Suffix string hashing still precomputes the hashes of the prefix, but this time it uses the largest base first and decreases the base as it moves on. Now, when we find the sum for a certain range, instead of having to divide by the power of the base, we have to multiply by the power of the base. This makes it much faster than prefix string hashing, because it is much easier to implement.

## Implementation

You can find a class-based static string implementation from USACO Guide at [`guide.cpp`](./guide.cpp)
