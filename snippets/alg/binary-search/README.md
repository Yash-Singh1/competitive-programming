# Binary Search

Binary Search works by dividing the search range by two each and every time it searches. This makes the algorithm run in $O(\log_2{n})$.

## BSTA (Binary Search The Answer)

The BSTA technique is a common technique in competitive programming problems where you divide all the possible answers for a correct one. This works only when you have a monotonic function that can represent the problem. For example, if given a number I can return a true or a false representing whether or not the number is a valid value, and we are asked to look for the maximal or minimal point, we can use binary search to search for that point. It would work by searching the upper half if the point we are looking at is true or false (depending on the problem) and search the lower half instead if the point we are looking at is the other boolean value.

## Searching Real Numbers

When searching for real numbers, instead of checking whether `low <= high`, we check if `high - low <= precision`. Where `precision` is the given error for the answer. This number is usually something like `1e-6` or `1e-8`. It is best to use a smaller number than the given one to handle precision errors. Also, when you are setting the lower and upper bounds based on the check, instead of doing something like `low = mid + 1`, we do `low = mid`, because this allows all the real numbers between `mid` and `mid + 1`. We also do a similar correction for setting the `high` value. My preferred way to check for when to terminate the loop is to not have a while loop, but instead have a for loop that runs a certain number of times, updating the bounds:

```cpp
ld l{0}, r{1e6L};

for (int i{0}; i < 50; ++i) {
  ld m{(l+r)/2};
  if (f(m)) {
    r = m;
  } else {
    l = m;
  }
}
```

We can adjust the $50$ to some other value depending on what our bounds are and what our precision is.

## Handling Negative Bounds

When binary searching with negative bounds, dividing will round up instead of down when dividing a odd negative integer. This means that when defining the middle variable, you need to use the following expression:

```cpp
lo + (hi - lo) / 2
```

## Searching Sorted Array

C++ has several builtin functions to leverage binary search to search sorted containers. These functions run in `O(\log_2{n})`. There are three main functions that we usually work with:

- `find` - `find` takes in the two iterators to search between and the value to search for in the third argument. It searches through a sorted container for an exact match of the value.

  ```cpp
  if (find(a.begin(), a.end(), 5) != a.end()) {
    cout << "Found 5" << endl;
  } else {
    cout << "No 5 found" << endl;
  }
  ```

- `upper_bound` - `upper_bound` searches takes the same argument format as `find` however it searches for a value that is $\gt$ than the given one in the sorted container.

- `lower_bound` - `lower_bound` works similarly to `upper_bound`, however it searches for a value that is $\ge$ to the given value.

You can also see some binary search snippets of lower bound and upper bound respectively, [`lower-bound.cpp`](./lower-bound.cpp) and [`upper-bound.cpp`](./upper-bound.cpp).

## Data Structures using Binary Search Based Techniques

Although, you don't need to be too aware of how they work internally, there are some non-linear data structures such as `set` and `map` that automatically sort the elements on insertion. Internally they make use of a data structure known as the binary search tree that is based on the principles of binary search.

## Finding Upper Bound

When you are not aware of the upper bound, a common practice that people use is to start off with $1$ and continuously multiply by 2 while the monotonic boolean function didn't change its value:

```cpp
int l{0}, r{1};
while (f(r)) r *= 2;
```

This is particularly useful for BSTA problems where we might not know the range we are searching.
