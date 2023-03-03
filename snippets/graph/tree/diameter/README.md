# Diameter of Tree

The diameter of a tree is the longest simple path between any two nodes in a tree.

## Finding Diameter

There are two ways to find the diameter of a tree.

### Double DFS Search

The double DFS search technique for finding the diameter of a tree finds the furthest node $a$ from any arbritary root of the tree and then finds the furthest node $b$ from the node $a$. The length of the diameter is the length of the distance between $a$ and $b$. This will run in $\mathcal{O}(n)$ time because we are just iterating over each node a constant number of times. The path isolation technique helps understand why this technique works. See [`diameter_doubledfs.cpp`](diameter_doubledfs.cpp) for an implementation.

### DP on Trees

Another technique for finding the diameter of a tree is using DP on trees. This technique maintains 2 DP arrays, one for the longest route to any node inside the current subtree and another for the longest route to any node outside the current subtree. We can also use this to calculate the longest path across the tree for each node that contains that node. This can be implemented in $\mathcal{O}(n)$ time also. Check out [`diameter_dp.cpp`](diameter_dp.cpp) for an implementation.

## Path Isolation

Path Isolation is a methodology of looking at a tree by stretching it out along the diameter. When visualizing a graph like this, we notice that the furthest node from any node would be lieing on one of the two endpoints which is an end of the diameter. Another observation we can make is that the closer you are to the center of the diameter path, the higher the maximum height of that subtree. For example, let's say we have a graph looking like this:

[![](https://mermaid.ink/img/pako:eNolTzEOwjAM_ErkuR2AwpARMcICjF5M4tKI1qnSRAhV_Ttp6sG6O59s3wzGWwYNbe-_pqMQ1fWOMqXXO9DYqQz2KCqXdYFNdF7U87wpJ1XXtcpjFouyK2zzr73QA8qhgAalKeCIAhUMHAZyNt-d110IseOBEXSGlsIHAWXJPkrRP35iQMeQuII0Wop8cZS_G0C31E9ZZeuiD7ctSMmz_AFozkP3?type=png)](https://mermaid.live/edit#pako:eNolTzEOwjAM_ErkuR2AwpARMcICjF5M4tKI1qnSRAhV_Ttp6sG6O59s3wzGWwYNbe-_pqMQ1fWOMqXXO9DYqQz2KCqXdYFNdF7U87wpJ1XXtcpjFouyK2zzr73QA8qhgAalKeCIAhUMHAZyNt-d110IseOBEXSGlsIHAWXJPkrRP35iQMeQuII0Wop8cZS_G0C31E9ZZeuiD7ctSMmz_AFozkP3)

Then the maximum height of `sub2` would be 1 and the maximum height of the subtree of 1 would be 0. For the subtree of 3, it would maximum height 2, but once we reach the subtree of 4 the maximum height resets to 1. The reason behind this is if the height exceeds the maximum height, then the path we are stretching on wouldn't be the diameter anymore. We can go down that subtree and get a larger diameter length.

Stretching a tree out by the diameter is often used in constructive thinking in tree problems.
