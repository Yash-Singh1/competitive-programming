# Minimum Spanning Tree

The minimum spanning tree is a subset of the edges of a connected, undirected graph that connects all the vertices together such that the sum of all the weights of the selected edges is minimal.

## Kruskal's Algorithm

Kruskal's Algorithm sorts all the edges in non-decreasing weight order and inserts them if needed one at a time. For each edge, it runs a DSU union between the two vertices. If the union changes nothing, then the edge isn't needed, otherwise the new edge contributes to the total weight of the minimum spanning tree. This algorithm runs in $O(E\log_2{E})$ time as it needs to sort the edges. The space complexity is $O(E)$. You can see an implementation in [kruskals.cpp](./kruskals.cpp).

## Prim's Algorithm

Prim's Algorithm works similar to Dijkstra, but instead it inserts edge weights in the priority queue, not the distance to the node. It starts with a single node and inserts all the edges that connect to it in the priority queue. Then it pops the minimum edge and inserts all the edges that connect to the other node of the edge. This process is continued until all the nodes are visited. Prim's Algorithm also runs in $O(E\log_2{E})$ times as priority queue insertions take $O(log_2(E))$ time. The space complexity is $O(E)$ as well, because we have to store all the edges in an adjacency list/matrix. You can see an implementation in [prims.cpp](./prims.cpp).

## Prim's Algorithm with Dense Graphs

Just like Dijkstra's algorithm, Prim's algorithm has a faster version for dense graphs. _TODO_

## Maximum Spanning Tree

_TODO_

## Minimum Spanning Forest

_TODO_

## Minimax/Maximin Problems

_TODO_

## Second Best ST in $O(VE)$

_TODO_
