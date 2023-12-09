#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // for every node in the tree, it has to be positioned optimally between the min of all descendants and the max of all descendants
  // from this we find the minimum imbalance to be the most dist between all of those
  // this can be run in O(n) time by using dp techniques for trees
  // the sol says we need to distinguish between left and right bounds
  // if l_i=r_i, then we can calc based on the min and max of the ancestors
  // however, when we have a range, we have a range, the range for the imbalance contrib
  // when we have a larger range, then the range is going to be on the max right most point and min left most point bcuz we want to still be in the middle and prevent going in the excess surroundings

  return 0;
}
