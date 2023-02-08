#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
	cin >> n;

  vector<int> c(n);
  for (int i{0}; i < n; ++i) cin >> c[i];

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

  for (int i{0}; i <= n; ++i) {
    for (int j{0}; j <= n; ++j) {
      if (i == j) dp[i][j] = 1;
      else if (i > j) {
        dp[i][j] = 0;
      } else if (i < n && j < n && i + 1 == j && c[i] == c[j]) {
        dp[i][j] = 1;
      } else if (i < n && j < n && i + 1 == j) {
        dp[i][j] = 2;
      }
    }
  }

  for (int i{n - 1}; i >= 0; --i) {
    for (int j{i+1}; j < n; ++j) {
      dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);
      // if (i == 1 && j == 2) {
      //   cout << dp[i][j] << " ";
      // }
      if (c[i] == c[i + 1]) dp[i][j] = min(dp[i][j], dp[i + 2][j] + 1);
      // if (i == 1 && j == 2) {
      //   cout << dp[i][j] << " ";
      // }
      for (int k{i + 2}; k <= j; ++k) {
        if (c[i] == c[k]) {
          dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
        }
      }
      // if (i == 1 && j == 2) {
      //   cout << dp[i][j] << "\n";
      // }
    }
  }

  // for (int i{0}; i < n; ++i) {
  //   cout << i << ": ";
  //   for (int j{i}; j < n; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  cout << dp[0][n - 1] << "\n";

  return 0;
}
