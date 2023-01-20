TODO: Move snippets to someplace else to make more accessible

## Catalog

| Name                   | Description                                                                 | File                                                      |
| ---------------------- | --------------------------------------------------------------------------- | --------------------------------------------------------- |
| BFS Shortest Path      | Returns the SSSP on an unweighted graph using BFS in $O(V+E)$               | [`graph/bfs_shortest`](./graph/bfs_shortest)              |
| Binary Search          | Basic binary search template $O(\log_2{n})$                                 | [`binary-search`](./binary-search)                        |
| Binary Exponentiation  | Allows you to exponentiate in $O(\log_2{b})$. Can be used with `mulpow.cpp` | [`math/binpow`](./math/binpow)                            |
| DFS                    | Depth First Search, $O(V+E)$                                                | [`graph/dfs`](./graph/dfs)                                |
| Factorial              | Iterative factorial with memoization in $O(n)$                              | [`math/factorial.cpp`](./math/factorial.cpp)              |
| Dynamic Programming    | Memoization technique to only iterate states                                | [`dynamic_programming`](./dynamic_programming/)           |
| Modular Multiplication | modular multiplication for mods $\ge10^9$ in $O(a\log_2(b))$                | _TODO_ [`math/mulmod`](./math/mulmod)                     |
| Floyd's Algorithm      | Tortoise and Hare Algorithm (Floyd's) for finding cycle in functional graph | _TODO_ ([Cooperative Game](../codeforces/1137D/main.cpp)) |
| Sieve of Eratosthenes  | Calculates which numbers are prime and which are not                        | [`math/prime`](./math/prime)                              |
| GCD                    | Greatest Common Divisor using Euclidean Algorithm in $O(\log_2(ab))$        | [`math/gcd`](./math/gcd)                                  |
| Rolling Hash           | Rolling Polynomial hash prefix sum calculation in $O(n)$                    | [`rolling_hash.cpp`](./rolling_hash.cpp)                  |
| Fenwick Tree           | Fenwick Tree, or BIT (Binary Index Tree) for efficient RSQ                  | [`fenwick_tree`](./fenwick_tree)                          |
| DSU                    | Disjoint Set Union, Data Structure representing graph components            | [`graph/dsu`](./graph/dsu)                                |
| Topological Sort       | Topological Sorting allows you to get an ordering of a DAG                  | [`graph/topological_sort`](./graph/topological_sort)      |
| Dijkstra               | SSSP on graphs without negative cycle                                       | [`graph/dijkstra`](./graph/dijkstra)                      |
| Bellman's Ford         | Bellman's Ford is a SSSP algorithm that detects negative cycles             | [`graph/bellmans-ford`](./graph/bellmans-ford)            |

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
