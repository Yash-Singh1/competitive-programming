#include <bits/stdc++.h>

using namespace std;

#define LSONE(s) (s & -s)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> cost(n, vector<int>(n));
  for (int i{0}; i <n ;++i) {
    for (int j{0}; j < n;++j) {
      cin >> cost[i][j];
    }
  }

  vector<vector<int>> dp(1<<n, vector<int>(n + 1, INT_MAX));
  dp[0][0] = 0;
  for (int i{1}; i < (1<<n); ++i) {
    for (int j{1}; j <= n; ++j) {
      int m{i};
      while (m) {
        dp[i][j] = min(dp[i][j], dp[i - LSONE(m)][j - 1] + cost[__builtin_ctz(m)][j - 1]);
        m -= LSONE(m);
      }
    }
  }

  cout << dp[(1<<n)-1][n] << "\n";

  return 0;
}
