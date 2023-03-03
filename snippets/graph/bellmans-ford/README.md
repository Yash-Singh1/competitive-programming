# Bellman's Ford

Bellman's Ford is an SSSP algorithm that runs in $\mathcal{O}(VE)$ time.

## Applications

Bellman's Ford is useful for finding the shortest path in a graph with negative cycles.

## What are Negative Cycles

Negative Cycles are cycles in a graph that have a summed weight less than 0. This can be a problem for SSSP problems because it means that there is no shortest path, we can cycle around in the graph forever and always get a shorter path.

## How it Works

Bellman's Ford works by "relaxing" each edge V-1 times. Relaxing an edge means checking if it can be used again to improve the distance of its destination node. It can be proven that if an edge can still be relaxed after V-1 iterations, then there is a negative cycle in the graph, so we can set the distance to the destination node as $-\infty$, indicating that it has been caught in a negative cycle.

## Implementation

You can see an implementation of Bellman's Ford algorithm in [`bellman.cpp`](./bellman.cpp).

## Time Complexity

The time complexity of Bellman's Ford is $\mathcal{O}(VE)$. This is because we have to iterate over each edge $V$ times.

## Moore's Optimization

Moore's Optimization for Bellman's Ford, also known as SPFA (Shortest Path Faster Algorithm) makes Bellman's Ford faster on average, but still has the same asymptotic time complexity. It works by running a BFS and relaxing edges coming out of the node in the BFS. You can see an modified implementation of SPFA from CP4 in [`spfa.cpp`](./spfa.cpp). There are a few more [minor optimizations](https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm#Optimization_techniques) possible in SPFA like using a dequeue to sort the nodes by distance, but I didn't implement them here.
