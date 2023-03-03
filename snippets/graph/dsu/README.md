# DSU (Disjoint Set Union)

DSU or Disjoint Set Union is a data structure used to represent disjoint sets by simply holding the parent of each element of a set.

## Applications

Disjoint Set Union can be applicable in many places. Some of them are:

- Simply holding disjoint sets and checking which one is part of which, performing unions, etc.
- Holding the components of an undirected graph, and print number of components every time edge is added
- Minimum Spanning Trees with Kruskal's algorithm

## Implementation

There are many forms of implementations for the Disjoint Set Union, each with their own advantages. I will go over the two main ones:

### QuickFind

`QuickFind` continuously sets the correct ancestor of each element in a set. This makes the find operation $\mathcal{O}(1)$, and the union operation $\mathcal{O}(n)$. You can see an implementation from LeetCode's Graph Theory modules in [`quickfind.cpp`](./quickfind.cpp).

### QuickUnion

`QuickUnion` unions the sets by simply setting the parent of the root of one of the sets to the other set's root. This makes the union operation $\mathcal{O}(n)$, and the find operation up till $\mathcal{O}(n)$. The union operation is still $\mathcal{O}(n)$ because we need to find the root of each set. You can see an implementation from LeetCode's Graph Theory modules in [`quickunion.cpp`](./quickunion.cpp).

## Optimizations

So far, none of the implementations of DSU that we saw were fast enough. They are pretty much the same speed asymptotically as a DFS search every time you add an edge. However, there are some optimizations that can be applied to make the amortized time complexity considerable as $\mathcal{O}(1)$.

### Union by Rank

Union by rank adds another array which represents the upper bound for the height of the DSU tree. If you connect the root of a larger tree to the root of a smaller tree, the resulting height will be less than connecting the root of a smaller tree to a larger tree. Because of this, the Union by Rank operation adds a check to swap the numbers if the rank of the first number is less than the rank of the second number.

### Union by Size

Union by Size is a bit more complicated to prove but allows you to use just one single array to store the size and the parent of each node, where Union by Rank requires you to use two arrays. It is preferred by the KACTL DSU template.

### Path Compression

Path Compression is a technique that doesn't recalculate the ancestor of an element if it has already been calculated. We can do this by making the `find` function a recursive function and on the way return `p[x] = find(p[x])`.

### Time Complexity

Combined, all of these operations make the time complexity the inverse of the Ackermann function, which is represented by the lowercase A in greek $\mathcal{O}(\alpha(n))$. In practice in competitive programming, we consider this to be approximately $\mathcal{O}(1)$, because the inverse Ackermann function grows very slowly. The time complexity of building the DSU is still $\mathcal{O}(n)$, as you have to initialize the array.

## Template

The most preferred template is the KACTL DSU implementation because it includes several optimizations and is well tested. You can find it in [`dsu.cpp`](./dsu.cpp).
