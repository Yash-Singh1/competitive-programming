#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("taming.in", "r", stdin);
  freopen("taming.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(202, vector<int>(n + 1, INT_MAX)));
  dp[0][0][1] = (a[0] == 0 ? 0 : 1);

  for (int i{0}; i < n - 1; ++i) {
    for (int j{0}; j <= 201; ++j) {
      for (int k{0}; k <= n; ++k) {
        if (dp[i][j][k] == INT_MAX) continue;
        if (k != n) dp[i + 1][0][k + 1] = min(dp[i + 1][0][k + 1], dp[i][j][k] + (a[i + 1] == 0 ? 0 : 1));
        if (j != 201) dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], dp[i][j][k] + (a[i + 1] == j + 1 ? 0 : 1));
      }
    }
  }

  for (int i{0}; i < n; ++i) {
    int ans{INT_MAX};
    for (int j{0}; j <= 201; ++j) {
      ans = min(ans, dp[n - 1][j][i+1]);
    }
    cout << ans << "\n";
  }

  return 0;
}
