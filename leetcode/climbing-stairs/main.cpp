class Solution {
public:
    int climbStairs(int n) {
        int a[n + 3];
      for (int i{0}; i <= n; ++i) {
        a[i] = 0;
      }
      a[0] = 1;
      for (int i{0}; i < n; ++i) {
        a[i + 1] += a[i];
        a[i + 2] += a[i];
      }
      return a[n];
    }
};
