# Topological Sort

Topological Sort gives an ordering of a directed acyclic graph (DAG) such that for each edge $u\rightarrow v$, $u$ appears before $v$ in the ordering.

## Applications

- Find prerequisites for a task
  - For example, I can give a possible ordering of a list of courses to take given their prerequisites
- Resolving dependency issues in Dynamic Programming
  - One problem often faced in Dynamic Programming is dependency issues where several results are required to compute the next result. If we compute the results in a topological sorted order, we can ensure that for every state, the dependencies are already computed.
- Finding cycles in graphs
  - If a graph has a cycle, then it is not possible to find a topological sort. This can be used to detect cycles in a graph and print them.

## DFS Implementation

The DFS implementation involves a recursive DFS implementation where you insert a node into the ordering after all the children have been visited. Then at the end, we can reverse the ordering. The time complexity of this is $O(V+E)$. The DFS implementation has the advantage of being able to detect cycles and backtrack, but there are a few advantages to the BFS version. You can see the implementation at [`dfs.cpp`](./dfs.cpp).

## Kahn's Algorithm

The BFS implementation of topological sort is known as Kahn's Algorithm. It consists of tracking the indegree of each node and adding nodes with an indegree of 0 to a queue. We can add the node to the ordering when we first find it in the queue because we know all its parents have been visited because its indegree has to be 0. The time complexity of this implementation is also $O(V+E)$. It allows you to also find the lexicographically smallest topological ordering and conduct iterative DP while doing topological sort. You can see the implementation at [`kahn.cpp`](./kahn.cpp).

## Lexicographically Smallest

The Kahn's Algorithm can be modified to instead use a `priority_queue` and work with the transpose of the graph and outdegrees instead. At the end you will have to reverse the ordering to get the answer.

## Dynamic Programming

Kahn's Algorithm can be modified to instead of pushing the node to the ordering, modify some sort of pull DP property of the node. Check out my solution for [CSES - Game Routes](https://cses.fi/problemset/task/1681) for an example of this.
