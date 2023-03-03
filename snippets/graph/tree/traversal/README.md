# Tree Traversals

There are several types of tree traversals that have different properties that they reveal of the tree.

## Preorder Traversal

A preorder traversal can be implemented fairly simply with an iterative DFS search. We push in the root first, then we push in all of the children of the current node. The preorder traversal is the technique used to find the Euler Tour of a tree which allows us to do efficient subtree updates and queries. The preorder traversal can also be used in conjunction with the postorder traversal to do a constant time ancestor check and implement a subtree searching algorithm for a certain property. The preorder traversal can be calculated in $\mathcal{O}(n)$ time, you can see an implementation at [`preorder_traversal.cpp`](./preorder_traversal.cpp).

## Postorder Traversal

Postorder traversal is a little more difficult to implement using an iterative approach, so usually people implement it recursively. The postorder traversal can be used in conjunction with the preorder traversal as described above. The postorder traversal can also be calculated in $\mathcal{O}(n)$ time, an implementation can be found at [`postorder_traversal.cpp`](./postorder_traversal.cpp).

## Inorder Traversal

Inorder traversal is more specific to binary trees.

## Level Order Traversal

Level order traversal allows us to get a list for each depth. This allows us to query for things based on certain levels. This can be implemented with a basic BFS search in $\mathcal{O}(n)$ time. You can find an implementation in [`levelorder_traversal.cpp`](./levelorder_traversal.cpp).

## Constant Time Ancestor Check

To run a constant-time ancestor check, first of all get the index of each node in the tree's preorder and postorder traversal. If some node $a$ is an ancestor of another node $b$, then the preorder traversal index would be smaller and the postorder index will be higher. We can show this shading in everything before in the preorder traversal and shading in everything after in a postorder traversal and looking at the intersection of the two areas in a sample tree.

## Timer Technique

The timer technique does the mix of a preorder and postorder traversal with a recursive DFS search. We maintain a timer and increment it before we start traversing the children and after we are done traversing the children. We store the timestamp of both of them for each of the nodes. Now if we want to find the # of descendants of a node with a certain property, we can simply have an array with all the start timestamps of all nodes with that property.
