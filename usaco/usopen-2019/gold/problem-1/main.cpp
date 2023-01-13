// O(n^3) bottom up can work here

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("snakes.in", "r", stdin);
  freopen("snakes.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  vector<int> groups(n);
  for (int i{0}; i < n; ++i) cin >> groups[i];

  vector<vector<int>> dp(n + 1, vector<int>(k + 1));
  int sm{0};
  int mx{0};
  for (int i{1}; i <= n; ++i) {
    mx = max(mx, groups[i - 1]);
    dp[i][0] = mx * i;
    for (int j{1}; j <= k; ++j) {
      dp[i][j] = INT_MAX;
      int cur{groups[i - 1]};
      for (int l{i - 1}; l >= 0; --l) {
        dp[i][j] = min(dp[i][j], dp[l][j - 1] + cur * (i - l));
        cur = max(cur, groups[l - 1]);
      }
    }
    sm += groups[i - 1];
  }

  cout << dp[n][k] - sm << "\n";

  return 0;
}
