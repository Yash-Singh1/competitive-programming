# Dynamic Programming

Dynamic Programming is a technique to solving problems with the following properties:

1. Optimal substructure: The optimal solution to the problem can be constructed from the optimal solutions to its subproblems.
2. Overlapping subproblems: We can divide the problem into subproblems with their own state that are overlapping.

## Top-down vs Bottom-up

There are two types of DP, top-down and bottom-up.

### Top-down DP

Top-down DP uses memoized recursion. It starts from the base input and makes its way down the recursion tree. If at any point, it comes across a state that it has already faced, it will return the memoized answer to that state.

## Bottom-up DP

Bottom-up DP involves calculating a table of values for all possible states. It starts from the base input and records the value of the next input based on a recurrence pattern between states.

## Difference

The difference between top-down DP and bottom-up DP is the following:

1. Top-down DP is recursive and bottom-up DP is iterative.
2. Top-down DP is more intuitive and bottom-up DP is more efficient.
3. Top-down DP searches only required states for answers while bottom-up DP searches all states for answers.
4. Top-down DP might have multiple calls on a single state to return its memoized value. Bottom-up DP only has one call on a state to return its value.
5. Bottom-up DP allows for use of less memory since it allows us to divide states into groups while top-down DP requires us to store all states because it does a Depth-First Search.

_TODO_ Write about classic DP problems, Knapsack, Digit, Bitmask, Range, etc.
