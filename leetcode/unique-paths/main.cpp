class Solution {
public:
    int uniquePaths(int m, int n) {
      if (m == 1 || n == 1) {
        return 1;
      }
        --m;
        --n;
      double ans{1};
      for (int i{m + 1}, j{2}; i <= m + n; ++i) {
        ans *= i;
        if (j <= n) ans /= j;
        ++j;
      }
      return ans;
    }
};
