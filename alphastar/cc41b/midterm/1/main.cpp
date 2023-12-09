#include <bits/stdc++.h>

using namespace std;

const int MOD = 5000011;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> dp(n, vector<int>(2, 0));
  for (int i{0}; i <= k; ++i) {
    dp[i][0] = 1;
  }
  dp[0][1] = 1;
  for (int i{0}; i < n-1; ++i) {
    for (int j{0}; j < 2; ++j) {
      dp[i+1][1] += dp[i][j];
      dp[i+1][1] %= MOD;
      if (i+k+1<n) {
        dp[i+k+1][0] += dp[i][j];
        dp[i+k+1][0] %= MOD;
      }
    }
  }

  cout << (dp[n-1][0] + dp[n-1][1])%MOD << '\n';

  return 0;
}
