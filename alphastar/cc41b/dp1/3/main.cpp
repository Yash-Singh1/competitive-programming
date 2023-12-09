#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n, vector<int>(m));
  vector<vector<int>> dp(n, vector<int>(m, -1));

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> g[i][j];
    }
  }

  dp[0][0] = g[0][0];
  for (int j{1}; j < m; ++j) {
    for (int i{0}; i < n; ++i) {
      if (i) {
        dp[i][j] = max(dp[i][j], (dp[i-1][j-1]==-1?-1:dp[i-1][j-1]+g[i][j]));
      }
      if (i<n-1) {
        dp[i][j] = max(dp[i][j], (dp[i+1][j-1]==-1?-1:dp[i+1][j-1]+g[i][j]));
      }
      dp[i][j] = max(dp[i][j], (dp[i][j-1]==-1?-1:dp[i][j-1]+g[i][j]));
    }
  }

  cout << dp[n-1][m-1] << '\n';

  return 0;
}
