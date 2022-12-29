#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<char>> a(n, vector<char>(n));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  if (a[0][0] == '*') {
    cout << 0 << "\n";
    return 0;
  }

  vector<vector<int>> dp(n, vector<int>(n));
  dp[0][0] = 1;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (i != n - 1 && a[i + 1][j] == '.') {
        (dp[i + 1][j] += dp[i][j]) %= MOD;
      }
      if (j != n - 1 && a[i][j + 1] == '.') {
        (dp[i][j + 1] += dp[i][j]) %= MOD;
      }
    }
  }

  cout << dp[n-1][n-1] << "\n";

  return 0;
}
