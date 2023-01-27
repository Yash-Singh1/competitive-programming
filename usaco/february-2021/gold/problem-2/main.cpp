#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  vector<vector<int>> dp(n, vector<int>(n));
  for (int i{0}; i < n; ++i) {
    dp[i][i] = 1;
  }

  for (int i{1}; i < n; ++i) {
    for (int j{0}; j + i < n; ++j) {
      dp[j][j + i] = INT_MAX;
      for (int k{j + 1}; k <= i + j; ++k) {
        dp[j][j + i] = min(dp[j][j + i], dp[j][k - 1] + dp[k][i + j]);
      }
      if (a[j] == a[j + i]) {
        --dp[j][j + i];
      }
    }
  }

  cout << dp[0][n - 1] << "\n";

  return 0;
}
