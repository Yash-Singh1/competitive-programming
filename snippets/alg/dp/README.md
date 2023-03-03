# Dynamic Programming

Dynamic Programming is a technique for solving recursive problems that have overlapping subproblems.

## Recognizing Dynamic Programming Problems

Dynamic Programming problems have the following properties:

1. Optimal substructure: The optimal solution to the problem can be constructed from the optimal solutions to its subproblems.
2. Overlapping subproblems: We can divide the problem into subproblems with their own state that are overlapping.

### Optimal Substructure

This means that there exists some optimal representation that we can store locally, which will allow us to still get the correct answer globally.

### Overlapping Subproblems

This means that we can run into one state several times. This is where DP shines. If we hit a state that has already been calculated, we can simply return the value in the DP array for that state. One visualization of this is when calculating grid paths. We can have a the number of ways to move from a certain cell precalculated, meaning that if we hit that cell from the other side, then we already have calculated the ways to the end from that cell.

### Top-down vs Bottom-up

There are two types of DP, top-down and bottom-up. Top-down problems involve literally implementing the solution recursively with a combination of some memoization. However bottom-up solutions iterate over every state and perform the transitions. Bottom-up solutions are generally faster, but less intuitive to implement as it doesn't come to us as naturally as a recursive solution.

### Push vs pull

Push DP and pull DP are two different ways of writing a recurrence. Both ways are fine when implementing, the one that you choose depends on your preferences. Push DP means that we update DP values that we will iterate into later on. Pull DP means that we use already precalculated DP values to calculate our current DP state.

### Formulating DAG

Every DP problem can also be formulated with a Directed Acyclic Graph (DAG). The transitions can be represented as edges in the graph and states can be represented as nodes. Visualizing a DP problem as a DAG sometimes helps out.

### Formulating Recurrences

Here are the steps for formulating a recurrence in DP:

1. Identify the states - Identify what we need to store in the states to have a small amount of states and we can optimally transition. Sometimes we can make greedy inferences to drop parameters or some parameters may be implicit.
2. Determine the base cases - Find out the initial states for the DP problem.
3. Make the transitions - This part is more difficult, you might have to revise your states, but find an optimal number of transitions so that you can solve the problem efficiently.

### Time Complexity

The time complexity of a DP solution is $\mathcal{O}(\texttt{states}+\texttt{transitions})$

## DP Paradigms

There are several types of DP problems that can be recognized and have their own patterns.

### Knapsack DP

Knapsack DP is used for finding properties on the possible sums of subsets of a set.

#### 0/1 Knapsack

The 0/1 Knapsack problem involves having a backpack and a bunch of items which each have a weight and a value. The goal is to find the optimal selection of items so the value is maximized and the weight is under the capacity of the backpack. We can't solve this greedily, because there could be a value that takes up too much space and doesn't allow others to fit in, however, we can solve the Fractional Knapsack problem greedily. Instead, we can solve this by having a DP array where the state is the current weight and the value is the maximum value we can get with that weight. Then we can iterate over each item and each weight and see if we can increase the value of the $\texttt{current weight}+\texttt{new item weight}$ by replacing it with the $\texttt{current value}+\texttt{new item value}$. This will run in $\mathcal{O}(\texttt{items}\cdot \texttt{capacity})$. For an implementation, see [`0-1_knapsack.cpp`](./0-1_knapsack.cpp).

We can also do the reverse, instead of storing $dp[weight]$, we store $dp[value]$ and iterate over each item and each possible value. This is useful when the maximum weight is too high, while the maximum value is low enough to iterate over. This in fact is what the point of the problem Atcoder - Knapsack 2 is.

#### Open-close Interval Trick

The open-close interval trick is a non-trivial DP technique for solving problems such as the following (from CSES - Coding Company):

> Given a sorted array of n workers and their skill levels, the penalty of a team is the difference between the skill levels of the best and worst coders in the team. In how many ways can we divide the n workers into teams such that the penalty level is at most x.

In this problem, we have to maintain several teams in our DP at the same time. We can do this with the open-close interval trick, where we would create a DP array like the following:

$$
dp[i][j][k] = \text{number of ways to make teams with the first } i \text{ workers such that the penalty is } k \text{ and their are } j \text{ teams still open for adding workers}
$$

Now if we are creating a new team, we would do the following transition: $dp[i + 1][j + 1][k - skill[i + 1]] \mathrel{{+}{=}} dp[i][j][k]$. The reason we are subtracting the penalty by the skill of the first person in the team is because they are the one with the least skill (the workers are sorted by skill) and since the penalty works like $best-worst$, the first coder's skill has to be subtracted when creating a new team.

If we are closing a team, we would do the following transition: $dp[i + 1][j - 1][k + skill[i + 1]] \mathrel{{+}{=}} dp[i][j][k]$. To close a team, we decrease the number of open teams and increase the skill because the last member is the best member.

The open-close interval trick can be expanded to other problems that involve making use of the ends of a subsequence.

### Longest Increasing Subsequence

The Longest Increasing Subsequence problem is a classic DP problem that involves finding the longest subsequence of an array that is increasing.

#### Implementation

We can implement the LIS problem in $\mathcal{O}(n\log_2{n})$ time by using some greedy assumptions. We can maintain a set of all of the elements currently in the LIS. Whenever we are deciding to put an element in a position, we just override its correct position in the set. If we end up having a longer suffix to our LIS, then it will override the entire final portion of the array and make its way to the end. If the newly inserted element is larger than all of the values in the set, then we insert a new element in the end of the set. In the end we can return the size of the set. If we want the exact value of the Longest Increasing Subsequence, we just need to make some modifications storing all of the elements previously occupying a position. If we want to implement the Longest **Non-decreasing** Subsequence instead of the Longest **Increasing** Subsequence, then we can simply replace the `lower_bound` in the implementation with a `upper_bound`, so we don't override duplicate elements. If we want to find the Longest **Decreasing** Subsequence instead of the Longest **Increasing** Subsequence, just reverse the array. You can find an implementation of LIS at [`lis.cpp`](./lis.cpp).

#### Dilworth's Theorem

Several competitive programming problems involving Longest Increasing Subsequence make use of Dilworth's Theorem. Dilworth's Theorem is a theorem from order theory that says the number of increasing subsequences needed to cover an array is equal the length of the Longest Decreasing Subsequence. This is useful for problems such as BOI 2010 - Printed Circuit Board:

> We have a circuit board with $n$ wires. Each wire has one end on one end of the board and another on the other en dof the board. We are given the $x$ position of the top end of the wire as $a$ and the $x$ position of the bottom end of the wire as $b$. No two wires connect to the same position on either end. We would like to add layers onto a circuit board, where each layer covers up a set of wires such that none of the wires overlap. Given the wires sorted by their $a$ position, find the minimum number of layers needed to cover all of the wires.

We can consider a layer as an increasing subsequence, because the $b$ values need to be increasing in order for them to not overlap with a previous $b$ value. Greedily removing the Longest Increasing Subsequence every time would take too long, up till $\mathcal{O}(n^2 \log_2{n})$. Instead we can use Dilworth's Theorem that says we simply need to find the Longest Decreasing Subsequence, which can be done in $\mathcal{O}(n \log_2{n})$ time.

### Counting

Several counting problems can be solved using DP, because we can eliminate to recount the solution to subproblems and instead just add or multiply them to the final answer.

#### Faster Modulus

Several counting problems have a complicated recurrence, require the use of the modulus operator (%) in several places. However, this can be very slow because the modulus operator is simply slower than other operations. Instead, we can use the following trick to speed up the modulus operator:

```cpp
// Addition
if (ans >= MOD) ans -= MOD;

// Subtraction
if (ans < 0) ans += MOD;
```

And that's it, we just subtract the modulus if it's too large. This technique can't be used in all cases, but try to use it where modulus is too overkill, such as when we are just adding large numbers.

### Grid

Grid problems are DP problems involving finding paths on a grid or counting common subsequences between two arrays.

#### Grid Paths

Finding the number of possible paths on a grid is a classic DP problem. Let's solve the following problem:

> Given a $n\times n$ grid where a $\texttt{\#}$ represents a wall and a $\texttt{.}$ represents an empty space, find the number of ways to get from the top left corner to the bottom right corner.

We can solve this problem by using a 2D DP array and the following recurrence:

```cpp
if (i < n - 1 && grid[i + 1][j] != '#') dp[i + 1][j] += dp[i][j];
if (j < n - 1 && grid[i][j + 1] != '#') dp[i][j + 1] += dp[i][j];
```

The base case would be $dp[0][0] = 1$. Most competitive programming problems won't be explicit about the fact that it's a grid problem, so you will have to figure out yourself that it involves counting grids.

#### Longest Common Subsequence

The Longest Common Subsequence problem is a classic DP problem that involves finding the longest subsequence of two arrays that is common to both arrays. This problem, like the Grid Paths problem can be solved in $\mathcal{O}(n^2)$ time using a 2D DP array. You can find an implementation of LCS at [`lcs.cpp`](./lcs.cpp). There are several other string DP problems such as CSES - Edit Distance that involve tweaking around the LCS recurrence a bit.

### Bitmask

Bitmask DP problems allow us to iterate over subsets and permutations in $\mathcal{O}(2^n)$ time.

One classic problem involving bitmask DP is the Traveling Salesman Problem (TSP). We can use DP to solve this problem because we can store the state of the current set of cities we have visited and the last city we visited. The involvement of bitmask DP in this permutations problem is that when we have a bitmask of say ${1, 2, 3}$, we would have already calculated the shortest path to visit cities ${1, 2}$. The same goes for if we have a set of ${1, 2, 4}$. As we can see, we are reusing the set of ${1, 2}$. We can represent the sets as an integer with each position being $1$ if the city is not in the set and $0$ if it is. The reason we are doing it the other way around is because we can make it two times faster by iterating over only the bits that are not in the set for consideration to adding to the set. For resolving dependency problems, we know that each subset of any set would already be precomputed. This is the case because the bitmask value for a subset of a set is always $\le$ to the bitmask to the set itself. For an implementation of the TSP problem, see [`tsp.cpp`](./tsp.cpp). This implementation runs in $\mathcal{O}(n^2 2^n)$ time.

Many bitmask DP problems require precomputation for bitmasks, such as calculating the sum of all the subsets of a set. This can easily done separately from the main DP code, just keep in mind that you can drop dimensions in DP that way.

### Range

Range DP involves us querying some information about a range.

#### Range DP with Sweep Line

Several Range DP problems can be solved using a sweep line approach. This could involve a $\mathcal{O}(n^3)$ solution where for computing $dp[i][j]$ (cost from $i$ to $j$), we need to find a $k$ such that $dp[i][k] + dp[k + 1][j]$ is minimal.

#### Counting Ranges in a Range

Some problems ask us to count the number of ranges in a range. For example, in USACO Gold - Farmer John Solves 3SUM, we have to count the number of triplets in each range. We can do so with the following formula which uses the Principle of Inclusion-Exclusion:

$$
dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + \text{\# of triplets starting at }i\text{ and ending at }j
$$

This formula is pretty common to be seen in a Range DP problem, so it's worth remembering.

### Digit

Digit DP is a non-trivial DP technique where we count the number of numbers with a certain property in a range. When we implement a digit DP solution, we usually make use of top-down DP, because it is much simpler with to implement with the large amount of dimensions in digit DP.

#### Calculating Numbers in a Range

When calculating the number of numbers in the range $[a, b]$, we can run a DFS search for the range $[0, b]$ and then subtract from that the result from the search on $[0, a-1]$. The first step before doing the DFS search is to convert the maximum into an array of digits:

```cp
vector<int> digits;

void regemx(ll mx) {
  digits.clear();
  while (mx) {
    digits.push_back(mx % 10);
    mx /= 10;
  }
}
```

When we are running the DFS search, there are two essential parameters, `pos` and `under`. `pos` defines the current position we are in calculating the possible numbers. `under` defines whether the current number we are calculating is less than the maximum number. If the first `pos` digits we are on are in some way less than the first `pos` digits of the maximum number, then the rest of the digits have no constraints. Otherwise if the first `pos` digits we are in matches the first `pos` digits of the maximum number, then the constraint for the next digit is that it has to be $\le \text{next digit of max number}$. For an example of using digit DP, see my [solution](https://cses.fi/paste/b6ceb9106b98e9bb5287d1/) to [CSES - Counting Numbers](https://cses.fi/problemset/task/2220).

#### Calculating Minimum Number

When calculating the minimum number with some constraints that is $\ge n$ for some given number $n$, we can do something similar to the previous Digit DP, except instead of `under` we use `over`. For finding the minimum, we can simply return a string of the digits instead of returning some number. We can then find the minimum over all of the strings of digits for each transition.

### Trees

DP on Trees problems involve calculating some properties of a tree. It is usually done by calculating that property for each subtree and then combining the results of the subtrees to get the result for the subtree of their parent.

#### Single Root

One classic problem with single root DP on trees is CSES - Tree Matching:

> What is the maximum number of distinct unordered pairs of nodes that are connected by an edge we can choose such that no node is part of more than one pair?

We can have a DP array where $dp[u][0] = \text{maximum number of pairs in the subtree of u where u is not in any pair}$ and $dp[u][1] = \text{maximum number of pairs in the subtree of u where u is in one pair}$. We can define the base cases and transitions as follows:

$$
dp[l][0] = 0\text{ for all leaf nodes }l
$$

This is because a leaf node can't be matched by any of its children, because it has no children.

$$
dp[u][0] = \sum_{v \in \text{children of }u} \max(dp[v][0], dp[v][1])
$$

Since $u$ is not in any pair, we just see what the optimal matchings are for each of its children and sum them up.

$$
sm = \sum_{v \in \text{children of }u} \max(dp[v][0], dp[v][1])\\
dp[u][1] = \max_{v \in \text{children of }u}(sm - \max(dp[v][0], dp[v][1]) + dp[v][0] + 1)
$$

Over here, for all of the children of $u$, we are using their optimal matching, except for one child $v$. For the child $v$, we instead use the $dp[v][0]$ value, because if we are matching $u$ with $v$, then $v$ must be unmatched first. We also add 1 to the sum because we just added another pair ${u, v}$. For an implementation of this, see my [solution](https://cses.fi/paste/47a0a66a6f431ebe519314/) to [CSES - Tree Matching](https://cses.fi/problemset/task/1130). The time complexity is $\mathcal{O}(n)$, because we are doing a DFS search on the tree.

#### Multiple Roots

Some problems require us to calculate the solution rerooting the tree every time we are calculating the DP value for another root. Solving DP problems with multiple roots often requires 2 DP arrays and DFS searches, one for inside the subtree and another for outside the subtree. Let's solve the problem CSES - Tree Distances I:

> Given a tree with $n$ nodes, for each node $i$ calculate the maximum distance path starting at node $i$.

A naive solution would be to run a DFS search from each node and find the maximum distance path. However, this would take $\mathcal{O}(n^2)$ time. We can do better using DP. Set up a DP array where $dp[u][0] = \text{maximumm distance path starting at }u\text{ within subtree}$ and $dp[u][1] = \text{maximum distance path starting at }u\text{ outside of subtree}$. We can define the base cases and transitions as follows:

$$
dp[l][0] = 0\text{ for all leaf nodes }l
$$

Leaf nodes can't go any further down because they don't have a subtree.

$$
dp[u][0] = \max_{v \in \text{children of }u}(dp[v][0] + 1)
$$

The maximum distance path starting at $u$ within the subtree is the maximum path within the subtree of any of its children plus 1.

$$
dp[u][1] = \max(dp[p][1], \max_{v \in \text{children of }p\setminus{u}}(dp[v][0] + 2))\text{ where }p\text{ is the parent of }u
$$

For calculating the maximum distance path starting at $u$ outside the subtree, we can have the parent use push DP to calculate it for $u$ and implement it in $\mathcal{O}(n)$. For an implementation of this, see my [solution](https://cses.fi/paste/acf00069517da5b55404b1/) for [CSES - Tree Distances I](https://cses.fi/problemset/task/1132).

## Tricks

There are several tricks and practices in DP.

### Dropping Parameters

When we are doing DP, look for ways to drop parameters. For example, if I can infer the value of a parameter in the state using other parameters in the state, then I can drop that parameter. Sometimes, we also have to make some greedy inferences which removes the need for a parameter. Also, some parameters are better off when they are precomputed. If we are getting a MLE, then check if we can reuse memory for previous DP states that will no longer be used. For example, if my DP transitions are always from $dp[i][j]$ to $dp[i + 1][j]$, then I can drop a dimension and instead maintain two arrays instead of one, e.g. $dp2[j] = ...dp1[j]...$, and at the end of each time we iterate over a new $i$, we run: `swap(dp1, dp2)`. This way, we reuse the memory of the previous array and don't have to allocate a new array for each $i$.
