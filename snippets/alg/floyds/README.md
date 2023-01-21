# Floyd's Algorithm

Floyd's Algorithm also known as the Tortoise and Hare Algorithm. Used for finding the cycle in a functional graphs.

## What is a Functional Graph?

A functional graph is a graph where each node has an outdegree of exactly one. Functional graphs are also often called circular linked lists or successor graphs. They contain one or more connected components with each component containing one cycle.

## What is Floyd's Algorithm?

Floyd's also known as the Tortoise and Hare Algorithm detects these cycles. It can output the length of the cycle ($\lambda$) or the starting node of the cycle ($\mu$).

## How Does it Work?

Phase 1 (finding $k\lambda$): Floyd's Cycle-Finding Algorithm works by maintaining two pointers, a fast pointer and a slow pointer, one going two steps at a time and the other one respectively. If the fast pointer cycles back to the slow pointer, a cycle is found. This is where the Tortoise and Hare analogy comes in, the fast pointer represents the hare and the slow pointer represents the tortoise from the well-known fable.

Phase 2 (finding $\mu$): Now we set the fast pointer back to the start and move both pointers one step at a time. When they meet, we have found the start of the cycle ($\mu$). We can skip the second phase if we don't need the start of the cycle.

Phase 3 (finding $\lambda$): Move the fast pointer until it reaches the same point it started at. The number of steps required for this is the cycle length ($\lambda$). We can skip the third phase if we don't need the cycle length.

## Time and Space Complexity

This algorithm has a time complexity of $O(n)$ and a space complexity of $O(1)$. The constant space is where this algorithm shines, allowing us to search large graphs and functions without using too much memory.

## Implementation

You can see an implementation in [`main.cpp`](./main.cpp). For an example of how to use this algorithm in a problem see my solution to the Codeforces problem [Cooperative Game](../../../codeforces/1137D/main.cpp). The problem statement can be found at Codeforces problem [1137D](https://codeforces.com/problemset/problem/1137/D).
