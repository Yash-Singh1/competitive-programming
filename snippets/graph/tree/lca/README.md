# LCA

The LCA, or Lowest Common Ancestor, of a tree is the deepest ancestor that is in common of two nodes. The LCA can be the node being compared itself.

## Applications

The main application of the LCA is to find properties on the path between two nodes. Since the LCA is in between the two nodes, it can be used as a checking point to find out useful properties about the path, such as its length, the number of nodes along the path in a certain category, etc.

## Binary Lifting LCA

LCA can be implemented with Binary Lifting by binary searching the depth that the two nodes need to jump to in order for them both to be at the same node. The time complexity of this approach is $O(\log_2^2{n})$ and the space complexity is $O(n\log_2{n})$ making it slower and less memory-efficient compared to the Euler Tour approach. See [`binary_lifting.cpp`](./binary_lifting.cpp) for an implementation using binary search + binary jumping to find the LCA.

## Euler Tour Technique

The Euler Tour technique for finding the LCA of two nodes starts off by generating a Euler Tour through a preorder traversal, but with one difference, that is we also push the vertex after each child's subtree. Then we insert the Euler Tour's depths into a segment tree or some other Range Minimum Query data structure and query the range between the first occurrences in the tour of each of the nodes. The LCA is the node with the minimum depth in the range. This approach has a time complexity of $O(n\log_2{n})$ to build and a $O(1)$ time complexity to query. The space complexity when using a sparse table would be the same as Binary Lifting, $O(n\log_2{n})$. To see an implementation of this approach, see [`euler_tour.cpp`](./euler_tour.cpp). I used segment tree in this implementation just because, but you can use a sparse table or any other Range Minimum Query data structure instead.
