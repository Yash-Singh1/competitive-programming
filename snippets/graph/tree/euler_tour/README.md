# Euler Tour

The Euler Tour technique is a method of flattening a tree so that we can perform subtree updates and queries by using it in conjunction with another data structure. It can also be slightly modified to also generate an array that can be queried upon with an RMQ data structure to find the LCA of two nodes in a tree.

## Flattening Tree

To flatten the tree, we simply run a preorder traversal on the tree. For example, if we have the following tree:

![Graph](graph.png)

The preorder traversal or Eulerian tour would look like:

```text
1 2 4 5 6 8 7 3
```

## Usage

Notice that each parent of a subtree is followed by all the nodes inside the subtree. For example, if we want to look at the subtree of 2, we just have to look between the indices of $[preorder[2] = 2, preorder[2] + size[2] - 1 = 7]$. We can make use of a Eulerian tour by inserting it into some data structure such as a segment tree or a Fenwick tree. One example application of this is to find the deepest node in a subtree. For this, we can use a Range Maximum Query data structure on a Eulerian tour storing the depth of each node.

## Time Complexity

The time complexity for finding a Eulerian Tour is $\mathcal{O}(n)$. There might be some logarithmic factor if you are using some data structure to store the result of the preorder traversal.

## Implementation

You can find an implementation at [`euler_tour.cpp`](./euler_tour.cpp).
