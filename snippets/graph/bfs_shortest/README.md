# BFS Shortest Path Algorithm

## SSSP on Unweighted Graph

BFS allows you to run SSSP on an unweighted graph with a simple BFS search because the first path to reach the final node is the shortest path, as each path is incremented one step at a time. Once the final node is reached, we can return the distance at that point and consider it as the minimum. The algorithm works by storing a distance array from a single source to any other node. The neighbors of each edge (excluding the parent) is then updated to the distance to the current node +1. The time complexity is the same as BFS, $\mathcal{O}(V+E)$. You can see the snippet in [`bfs_shortest.cpp`](./bfs_shortest.cpp).

## 0/1 Breadth First Search

The basic idea of 0/1 BFS is to use a dequeue to store the zero based edges first and the one based edges last in a graph with weights that are either zero or one. This works similarly to Dijkstra, however it doesn't need any non-linear time complexity data structure and only stores the edge. This runs in $\mathcal{O}(V+E)$. You can view the snippet in [`01bfs.cpp`](./01bfs.cpp).

## Dial's Algorithm

The Dial's Algorithm works similarly to 0/1 BFS, but expands it to $k$ possible weights. It stores a list of queues instead of simply using a dequeue. This algorithm should only be used when $k$ is minimal and runs in $\mathcal{O}(k(V+E))$. You can see an implementation of this in [`dials.cpp`](./dials.cpp).
