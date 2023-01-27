#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("248.in", "r", stdin);
  freopen("248.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  vector<vector<int>> dp(n, vector<int>(n));
  int ans{0};
  for (int i{n - 1}; i >= 0; --i) {
    for (int j{i}; j < n; ++j) {
      if (i == j) {
        dp[i][j] = a[i];
      } else {
        dp[i][j] = -1;
        if (a[i] == dp[i + 1][j]) {
          dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
        }
        if (a[j] == dp[i][j - 1]) {
          dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
        }
        for (int k{i + 1}; k < j; ++k) {
          if (dp[i][k] == dp[k + 1][j] && dp[i][k] != -1) {
            dp[i][j] = dp[i][k] + 1;
          }
        }
      }
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << "\n";

  return 0;
}
