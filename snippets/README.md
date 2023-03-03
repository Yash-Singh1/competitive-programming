TODO: Move snippets to someplace else to make more accessible

## Catalog

| Name                   | Description                                                                           | File                                                 |
| ---------------------- | ------------------------------------------------------------------------------------- | ---------------------------------------------------- |
| BFS Shortest Path      | Returns the SSSP on an unweighted graph using BFS in $\mathcal{O}(V+E)$               | [`graph/bfs_shortest`](./graph/bfs_shortest)         |
| Binary Search          | Basic binary search template $\mathcal{O}(\log_2{n})$                                 | [`alg/binary-search`](./alg/binary-search)           |
| Binary Exponentiation  | Allows you to exponentiate in $\mathcal{O}(\log_2{b})$. Can be used with `mulpow.cpp` | [`math/binpow`](./math/binpow)                       |
| DFS                    | Depth First Search, $\mathcal{O}(V+E)$                                                | [`graph/dfs`](./graph/dfs)                           |
| Factorial              | Iterative factorial with memoization in $\mathcal{O}(n)$                              | [`math/factorial.cpp`](./math/factorial)             |
| Dynamic Programming    | Memoization technique to prevent recalculation for states                             | [`alg/dp`](./alg/dp/)                                |
| Modular Multiplication | modular multiplication for mods $\ge2^{32}$ in $\mathcal{O}(a\log_2(b))$              | [`math/mulmod`](./math/mulmod)                       |
| Floyd's Algorithm      | Tortoise and Hare Algorithm (Floyd's) for finding cycle in functional graph           | [`alg/floyds`](./alg/floyds)                         |
| Sieve of Eratosthenes  | Calculates which numbers are prime and which are not                                  | [`math/prime`](./math/prime)                         |
| GCD                    | Greatest Common Divisor using Euclidean Algorithm in $\mathcal{O}(\log_2(ab))$        | [`math/gcd`](./math/gcd)                             |
| Rolling Hash           | Rolling Polynomial hash prefix sum calculation in $\mathcal{O}(n)$                    | [`alg/rolling_hash`](./alg/rolling_hash)             |
| Fenwick Tree           | Fenwick Tree, or BIT (Binary Index Tree) for efficient RSQ                            | [`ds/fenwick_tree`](./ds/fenwick_tree)               |
| Segment Tree           | A data structure used to store dynamic associative results on segments                | [`ds/segment_tree`](./ds/segment_tree)               |
| DSU                    | Disjoint Set Union, Data Structure representing graph components                      | [`graph/dsu`](./graph/dsu)                           |
| Topological Sort       | Topological Sorting allows you to get an ordering of a DAG                            | [`graph/topological_sort`](./graph/topological_sort) |
| Dijkstra               | SSSP on graphs without negative cycle                                                 | [`graph/dijkstra`](./graph/dijkstra)                 |
| Bellman's Ford         | Bellman's Ford is a SSSP algorithm that detects negative cycles                       | [`graph/bellmans-ford`](./graph/bellmans-ford)       |
| Minimum Spanning Tree  | Minimum Spanning Tree (MST) is minimal weight tree spanning a graph                   | [`graph/mst`](./graph/mst)                           |
| Pascal's Identity      | Algorithm to progressively memoize binomials in $\mathcal{O}(NR)$                     | [`math/pascals`](./math/pascals)                     |
| PIE                    | Counts number of elements in subsets given set relationship                           | [`math/pie`](./math/pie)                             |
| Tree Diameter          | Finding the diameter of a tree and its applications                                   | [`graph/tree/diameter`](./graph/tree/diameter)       |
| Euler Tour             | Euler Tour technique for querying/updating subtrees                                   | [`graph/tree/euler_tour`](./graph/tree/euler_tour)   |
| Tree Traversals        | Different methods of traversing a tree and their applications                         | [`graph/tree/traversal`](./graph/tree/traversal)     |
| Sparse Tables          | Static range and binary lifting query data structure                                  | [`ds/sparse_tables`](./ds/sparse_tables)             |
| LCA                    | Find the Lowest Common Ancestor between two nodes                                     | [`graph/tree/lca`](./graph/tree/lca)                 |

## Personal Choices in Starter Template

These are a few suggestions for starter templates and their explanations.

### `bits/stdc++.h`

I import `bits/stdc++.h` to get access to all libraries straight in the beginning.
Some people worry about this taking up too much space in the compiled output,
however it doesn't take a significant amount and some judges may even run dead
code elimination on the output in the process.

### `using namespace std`

While this is a bad practice in an enterprise environment due to namespace conflict,
it is fine to use in competitive programming as long as you are aware of how you're
naming your variables, because in competitive programming you want to implement your
solution faster.

### `ios_base::sync...`

Read the following links on why this speeds up I/O (Input and Output):

- [StackOverflow Question](https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull)
- [USACO Guide Article](https://usaco.guide/general/fast-io?lang=cpp#iossync_with_stdiofalse)
