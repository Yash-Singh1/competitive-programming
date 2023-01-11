TODO: Move snippets to someplace else to make more accessible

## Catalog

| Name                   | Description                                                                  | File                                                      | Source                                                            |
| ---------------------- | ---------------------------------------------------------------------------- | --------------------------------------------------------- | ----------------------------------------------------------------- |
| BFS Shortest Path      | Returns the SSSP on an unweighted graph using BFS in $O(V+E)$                | [`bfs_shortest`](./bfs_shortest)                          | -                                                                 |
| Binary Search          | Basic binary search template $O(log_2 n)$                                    | [`binary-search`](./binary-search)                        | -                                                                 |
| Binary Exponentiation  | Allows you to exponentiate in $O(alog_2 (b))$. Can be used with `mulpow.cpp` | [`binpow.cpp`](./binpow.cpp)                              | -                                                                 |
| Iterative DFS          | Depth First Search implemented iteratively, $O(V+E)$                         | [`dfs_iterative.cpp`](./dfs_iterative.cpp)                | -                                                                 |
| Factorial              | Iterative factorial with memoization in $O(n)$                               | [`factorial.cpp`](./factorial.cpp)                        | -                                                                 |
| LCS                    | Longest Common Subsequence tabulated with iterative DP in $O(nm)$            | [`lcs-tabulated.cpp`](./lcs-tabulated.cpp)                | -                                                                 |
| Modular Multiplication | modular multiplication for mods $>=10^9$ in $O(a\log_2(b))$                  | [`mulmod.cpp`](./mulmod.cpp)                              | GeeksForGeeks                                                     |
| Floyd's Algorithm      | Tortoise and Hare Algorithm (Floyd's) for finding cycle in functional graph  | _TODO_ ([Cooperative Game](../codeforces/1137D/main.cpp)) | -                                                                 |
| Sieve of Eratosthenes  | Calculates which numbers are prime and which are not in $O(n\log_2(n))$      | [`prime.cpp`](./prime.cpp)                                | -                                                                 |
| Linear Sieve           | Calculates which numbers are prime using optimizations in $O(n)$             | [`linear_sieve.cpp`](./linear_sieve.cpp)                  | [Nisiyama_Suzune's blog](https://codeforces.com/blog/entry/54090) |
| GCD                    | Greatest Common Divisor using Euclidean Algorithm in $O(\log_2(ab))$         | [`gcd.cpp`](./gcd.cpp)                                    | USACO Guide                                                       |
| Rolling Hash           | Rolling Polynomial hash prefix sum calculation in $O(n)$                     | [`rolling_hash.cpp`](./rolling_hash.cpp)                  | -                                                                 |
| Fenwick Tree           | Fenwick Tree, or BIT (Binary Index Tree) for efficient RSQ                   | [`fenwick_tree`](./fenwick_tree)                          | CP4                                                               |
| DSU                    | Disjoint Set Union, Data Structure representing graph components             | [`dsu`](./dsu)                                            | LeetCode/KACTL                                                    |

## Personal Choices in Starter Template

These are a few suggestions for starter templates and their explanations.

### `bits/stdc++.h`

I import `bits/stdc++.h` to get access to all libraries straight in the beginning.
Some people worry about this taking up too much space in the compiled output,
however it doesn't take a significant amount and some judges may even run dead
code elimination on the output in the process.

## `using namespace std`

While this is a bad practice in an enterprise environment due to namespace conflict,
it is fine to use in competitive programming as long as you are aware of how you're
naming your variables, because in competitive programming you want to implement your
solution faster.

## `ios_base::sync...`

Read the following links on why this speeds up I/O (Input and Output):

- [StackOverflow Question](https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull)
- [USACO Guide Article](https://usaco.guide/general/fast-io?lang=cpp#iossync_with_stdiofalse)
