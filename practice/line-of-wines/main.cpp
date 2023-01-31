#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  dp[0][0] = 0;
  for (int i{0}; i <= n; ++i) {
    for (int j{0}; j <= n; ++j) {
      if (i + j >= n) break;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (i + j + 1) * a[i]);
      dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + (i + j + 1) * a[n - j - 1]);
    }
  }

  int ans{0};
  for (int i{0}; i <= n; ++i) {
    ans = max(ans, dp[i][n - i]);
  }

  cout << ans << "\n";

  return 0;
}
