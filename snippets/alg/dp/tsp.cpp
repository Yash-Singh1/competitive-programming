#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  // Distance from i to j
  vector<vector<int>> d(n+1, vector<int>(n+1));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> d[i][j];
    }
  }

  // dp[bitmask][last]
  vector<vector<int>> dp(1<<n, vector<int>(n+1, INT_MAX));
  dp[(1<<n)-1][n] = 0;
  int ans{INT_MAX};
  for (int i{(1<<n)-1}; i >= 0; --i) {
    for (int j{0}; j <= n; ++j) {
      if (dp[i][j] == INT_MAX) continue;
      if (!i) ans = min(ans, dp[i][j]);
      int b{i};
      while (b) {
        dp[i^LSOne(b)][__builtin_ctz(b)] = min(dp[i^LSOne(b)][__builtin_ctz(b)], dp[i][j] + d[j][__builtin_ctz(b)]);
        b -= LSOne(b);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
