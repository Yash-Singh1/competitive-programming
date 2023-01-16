# Dijkstra

Dijkstra solves the SSSP problem efficiently on graphs with non-negative edge weights. It runs in $O(E\log_2 V)$ time, but also has a faster alternative for dense graphs that runs in $O(V^2)$.

## Applications

- Efficient routing in Google Maps
- Analyzing relationships on social media
- Fastest route using public transportation

## How it Works

Dijkstra works using a greedy approach. It maintains a priority queue containing the distance and the node. Each time Dijkstra runs, it starts with the node with the least distance and advances it further. It keeps on doing this until it reaches the destination node. The algorithm may not work properly on graphs with negative weights because Dijkstra can't see that there is a very effective negative edge ahead on a path, it will instead just try some more promising path.

## Implementation

You can see an implementation of Dijkstra for sparse graphs in [`dijkstra.cpp`](./dijkstra.cpp).
