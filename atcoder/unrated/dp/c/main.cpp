#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n), b(n), c(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }

  // cout << "--------\n";

  vector<vector<int>> dp(n, vector<int>(3));
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];
  for (int i{1}; i < n; ++i) {
    for (int j{0}; j < 3; ++j) {
      for (int k{0}; k < 3; ++k) {
        if (k != j) {
          dp[i][j] = max(dp[i][j], dp[i - 1][k] + (j == 0 ? a[i] : (j == 1 ? b[i] : c[i])));
        }
      }
      // cout << dp[i][j] << " ";
    }
    // cout << "\n";
  }

  cout << max(dp[n-1][0], max(dp[n - 1][1], dp[n - 1][2])) << "\n";

  return 0;
}
