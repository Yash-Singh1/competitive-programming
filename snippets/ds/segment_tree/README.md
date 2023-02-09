# Segment Tree

Segment tree is an efficient data structure for storing information on segments, such as the minimum, maximum, sum, etc.

## Basic Operations Supported

Segment tree allows you to efficiently find the answer to any associative operation on a segment. This includes minimum, maximum, sum, product, gcd, etc.

## How It Works

Segment tree works by splitting the array into segments of each power of 2. For example, if the array is of size 4, then the segments will be $[1, 1]$, $[2, 2]$, $[3, 3]$, $[4, 4]$, $[1, 2]$, $[3, 4]$, and $[1, 4]$. If the array's size is not a power of 2, then the array is resized to be the length of the next power of 2. The remaining elements will be filled in with default values, called units. We can represent a segment tree like a tree:

```text
          [1, 4]
          /    \
    [1, 2]      [3, 4]
    /    \      /    \
[1, 1] [2, 2] [3, 3] [4, 4]
```

## Array Format

Although a segment tree is represented conceptually as a tree, we store it as an array for efficiency. For each element, $x$, the node on the right is $2x+2$ and the node on the left is $2x+1$. This allows us to recursively search through the segment tree for correct matches and update them accordingly. Since there are a max of $2^{\lceil{\log_2(n)}\rceil+1}$, the space complexity of a segment tree is $O(n)$.

## Range Queries

When doing range queries, we can recursively go through intersecting elements in the segment tree with the range. For example, in the case of the 4 element segment tree shown above, if we want to find the sum of the range $[2, 4]$, we could:

1. Start at the root node, $[1, 4]$. This node has a partial intersection with the query range, so we go to the left child, $[1, 2]$.
2. This node also has a partial intersection with the query range, so we go to the left child, $[1, 1]$.
3. This node is out of the range of the query, so skip it and move onto the right child, $[2, 2]$.
4. This node has a full intersection with the query range, so we add its value to the answer.
5. Now we search the right child of the root, $[3, 4]$.
6. This node has a full intersection with the query range so we add its value to the answer.

This entire process takes about $O(\log_2{n})$ time.

## Point Updates

_TODO_

## Range Updates

## Point Queries

_TODO_

## Range Queries

_TODO_
## Build Operation

_TODO_

## kth Minimum Query

_TODO_

## Lazy Propagation

_TODO_

## Implementation

You can find a basic implementation of a segment tree at [`segment_tree.cpp`](./segment_tree.cpp). For a more efficient implementation from KACTL see [`kactl.cpp`](./kactl.cpp).
