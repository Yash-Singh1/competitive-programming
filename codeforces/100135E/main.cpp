#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("slalom.in", "r", stdin);
  // freopen("slalom.out", "w", stdout);

  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(n));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= i; ++j) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
  for (int i{0}; i < n; ++i) {
    dp[n - 1][i] = a[n - 1][i];
  }

  for (int i{n - 1}; i > 0; --i) {
    for (int j{0}; j <= i; ++j) {
      if (j != i) {
        dp[i - 1][j] = max(dp[i - 1][j], dp[i][j] + a[i - 1][j]);
      }
      if (j != 0) {
        dp[i - 1][j - 1] = max(dp[i - 1][j - 1], dp[i][j] + a[i - 1][j - 1]);
      }
    }
  }

  cout << dp[0][0] << "\n";

  return 0;
}
