class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
      int a[n + 5];
      for (int i{0}; i <= (n + 2); ++i) {
        a[i] = -1;
      }
      a[0] = 0;
      a[1] = 0;
      for (int i{0}; i < n; ++i) {
        a[i + 1] = min(cost[i] + a[i], a[i + 1] == -1 ? (INT_MAX - 5) : a[i + 1]);
        a[i + 2] = min(a[i + 2] == -1 ? (INT_MAX - 5) : a[i + 2], cost[i] + a[i]);
      }
      return min(a[n], a[n + 1]);
    }
};
