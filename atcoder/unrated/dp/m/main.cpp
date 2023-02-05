#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,k;
  cin >> n >> k;

  vector<int> req(n);
  for (int i{0}; i < n; ++i) cin >> req[i];

  vector<vector<int>> dp(n+1, vector<int>(k + 1));
  dp[0][0] = 1;
  vector<int> diff(k+1);
  for (int i{0}; i < n; ++i) {
    // diff[0] = dp[i][0];
    // for (int j{1}; j < n; ++j) {
    //   diff[j] = dp[i][j] - dp[i][j - 1];
    // }
    diff.assign(k+2, 0);
    for (int l{0}; l <= k; ++l) {
      // From l to min(k, l + req[i])
      // we can use difference array and prefix sums
      diff[l] += dp[i][l];
      if (diff[l] >= MOD) diff[l] -= MOD;
      int r{min(k, l + req[i]) + 1};
      diff[r] -= dp[i][l];
      if (diff[r] < 0) diff[r] += MOD;
      // for (int j{0}; j + l <= k && j <= req[i]; ++j) {
      //   dp[i + 1][j + l] += dp[i][l];
      //   if (dp[i + 1][j + l] >= MOD) dp[i + 1][j + l] -= MOD;
      // }
    }
    dp[i + 1][0] = diff[0];
    for (int j{1}; j <= k; ++j) {
      dp[i + 1][j] = dp[i + 1][j - 1] + diff[j];
      if (dp[i + 1][j] < 0) dp[i + 1][j] += MOD;
      if (dp[i + 1][j] >= MOD) dp[i + 1][j] -= MOD;
    }
  }

  cout << dp[n][k] << "\n";

  return 0;
}
