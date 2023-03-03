# Minimum Spanning Tree

The minimum spanning tree is a subset of the edges of a connected, undirected graph that connects all the vertices together such that the sum of all the weights of the selected edges is minimal.

## Kruskal's Algorithm

Kruskal's Algorithm sorts all the edges in non-decreasing weight order and inserts them if needed one at a time. For each edge, it runs a DSU union between the two vertices. If the union changes nothing, then the edge isn't needed, otherwise the new edge contributes to the total weight of the minimum spanning tree. This algorithm runs in $\mathcal{O}(E\log_2{E})$ time as it needs to sort the edges. The space complexity is $\mathcal{O}(E)$. You can see an implementation in [kruskals.cpp](./kruskals.cpp).

## Prim's Algorithm

Prim's Algorithm works similar to Dijkstra, but instead it inserts edge weights in the priority queue, not the distance to the node. It starts with a single node and inserts all the edges that connect to it in the priority queue. Then it pops the minimum edge and inserts all the edges that connect to the other node of the edge. This process is continued until all the nodes are visited. Prim's Algorithm also runs in $\mathcal{O}(E\log_2{E})$ times as priority queue insertions take $\mathcal{O}(log_2(E))$ time. The space complexity is $\mathcal{O}(E)$ as well, because we have to store all the edges in an adjacency list/matrix. You can see an implementation in [prims.cpp](./prims.cpp).

## Prim's Algorithm with Dense Graphs

Just like Dijkstra's algorithm, Prim's algorithm has a faster version for dense graphs. Prim's Dense Algorithm works by storing the minimum edge connecting to a selected vertex and selecting one vertex at a time, the vertex with the minimum edge weight connecting to a selected vertex. Then, we have to update all the neighbors of the newly vertex with the new edge weight (if it is smaller than the current one). This algorithm takes $\mathcal{O}(V^2+E)$ time because we need to iterate over all vertices each and every time and their edges. The space complexity is $\mathcal{O}(V+E)$ because we need to store the minimum edge for each vertex and the adjacency lists. You can see an implementation in [prims_dense.cpp](./prims_dense.cpp).

## Maximum Spanning Tree

We can calculate the maximum spanning tree of a graph in a similar way as the minimum spanning tree, except when using the Kruskal's algorithm we sort it in non-increasing order and when using Prim's algorithm we use a max priority queue for the sparse version and find the max edge instead for the dense version.

## Minimum Spanning Forest

When we are given a disconnected graph, there is the notion of a minimum spanning forest. In the minimum spanning forest, each connected component of the graph has its own minimum spanning tree. The minimum spanning forest is the union of all the minimum spanning trees of the connected components. It can be calculated by running Kruskal's algorithm as usual, but without the DSU check ensuring we have a single connected component.

## Minimax/Maximin Problems

The minimax/maximin problem is another type of problem where the minimum or the maximum edge used is asked for. We can calculate this by simply calculating the spanning tree, but instead of summing up all the weights, find the minimum or maximum of them.

## Second Best ST in $\mathcal{O}(VE)$

We can modify Kruskal's Algorithm to find the second best spanning tree:

1. Sort the edges
2. Calculate the ST
3. Iterate over each edge in the ST
  - Recalculate the ST without that edge

The second best ST will be the minimum or maximum of all of the results. The time complexity is $\mathcal{O}(E\log_2{E}+E+VE) = \mathcal{O}(VE)$. The third step takes $\mathcal{O}(VE)$ because there is only $V-1$ edges in the ST, so we have to recalculate the ST $V-1$ times.
