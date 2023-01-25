# Modular Multiplication

Modular multiplication allows us to calculate $a\cdot b$ in $O(a\log_2{b})$ time.

## Applications

When we are given a problem that involves multiplication $\mod{\gt 10^9}$, we can use this algorithm to calculate the result without integer overflow for `long long`. Another alternative could be to use `__int128` in C++.

## How it Works

The implementation for modular multiplication works similar to that of `binpow`, except we are adding $a$, $b$ times.

## Implementation

You can see an implementation from GeeksForGeeks at [`mulmod.cpp`](./mulmod.cpp). I also have a `__int128` casting based implementation in [`mulmod_cast.cpp`](./mulmod_cast.cpp).
