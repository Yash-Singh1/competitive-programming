# DFS

DFS, or depth-first search, is a technique for traversing through nodes in a graph.

## How it Works

DFS works by maintaining a stack and inserting into that stack whenever a new edge is found for the currently evaluated node. If a visited node is reached, then we skip it to prevent infinite loops. When the stack is empty, the entire graph has been traversed.

## Applications

DFS has a number of applications:

- Counting components, performing floodfill
- Subtree sums
- Finding some basic property of nodes in a graph
- Finding properties of components

## Iterative

Here is an iterative implementation of DFS, [`dfs_iterative.cpp`](./dfs_iterative.cpp).

## Recursive

Recursive DFS is often more memory-consuming for larger graphs, but allows for running code after the children have been traversed, which is useful for some applications. Here is a recursive implementation of DFS, [`dfs_recursive.cpp`](./dfs_recursive.cpp).

## Time Complexity

Since it has to traverse each node once, and each edge once, DFS has a time complexity of $O(V+E)$.

## Space Complexity

Since we have to store the edges in an adjacency list and the nodes in the visited array, the space complexity is also $O(V+E)$.
