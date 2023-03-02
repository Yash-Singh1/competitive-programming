# Sparse Tables

Sparse Tables allow us to create a static range query structure in $O(n\log_2{n})$ time for associative operations.

## How it Works

Sparse Tables work by maintaining the result of running the operation for the following power of two values. This allows us to look at each of the bits of the length of the range query and running the operation for each of the $\log_2{n}$ bits.

## Applications

We can use a sparse table to:

- Calculate static range queries of operations with the associative property
- Calculate static range queries of operations that are idempotent in constant time
- Binary Lifting, finding the $k$th ancestor of a particular node

## PseudoCode

Here is some code on how an implementation might look like:

```cpp
// Range Sum Query Implementation

// Build
vector<int> val(n);
vector<vector<int>> table(n, vector<int>(30, -1)); // -1 means out of bounds
for (int j{0}; j < 30; ++j) {
  for (int i{0}; i < n; ++i) {
    if (!j) {
      table[i][0] = val[i];
    } else {
      if (table[i][j - 1] == -1 || table[i+(1<<(j-1))][j - 1] == -1 || i+(1<<(j-1)) >= n) continue;
      table[i][j] = table[i][j - 1] + table[i+(1<<(j-1))][j - 1];
    }
  }
}

// Query
int l, r;
r = r-l+1;
int ans = 0;
while (r) {
  ans += table[i][__builtin_ctz(r)];
  r -= LSOne(r);
}
```

## Time Complexity

The time complexity for precomputing is $O(n\log_2{n})$ because we must compute each and every power of two that reaches $n$, $n$ times each for each element. The query operation takes $O(\log_2{n})$, because we must traverse the bits of the length and the length is at most $n$.

## Overlapping Technique

We can also calculate the answer to a range query in constant time if the operation is idempotent, such as `max` or `min`. We can do this by realizing that any range can be divided into two possibly overlapping ranges that are both the same power of two length. We can calculate the length of this range by taking the most significant bit (MSB) of the length of the entire range. Then we can output the answer as the right side of the range with the MSB length and the left side of the range with the MSB length. This is because the operation is idempotent, so the answer will be the same regardless of the order of the operation. This gives us a $O(1)$ time complexity for querying.

## Implementation

You can see an implementation for Range Minimum Query from my solution to the CSES problem - Static Range Minimum Queries in [`rmq.cpp`](./rmq.cpp). For my solution to the same problem using the overlap technique, see [`overlap.cpp`](./overlap.cpp) You can see an implementation for Binary Lifting from my solution to CSES problem - Company Queries I in [`binary_lifting.cpp`](./binary_lifting.cpp).
