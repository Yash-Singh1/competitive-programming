#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  dp[0][0] = 1;
  for (int i{1}; i <= n; ++i) {
    dp[i][0] = dp[i - 1][0];
    for (int j{1}; j <= n; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }

  // dp[i][j] is C(i, j)

  return 0;
}
