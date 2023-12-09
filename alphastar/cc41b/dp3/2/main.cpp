#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int c, n;
  cin >> c >> n;

  vector<vector<int>> dp(2, vector<int>(c+1));
  int x;
  dp[0][0] = 1;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    for (int j{0}; j <= c; ++j) {
      if (dp[0][j]) {
        dp[1][j] |= dp[0][j];
        // if (j+x == 32) {
        //   cout << j << ' ' << dp[i][j] << ' ' << x << '\n';
        // }
        if (j+x <= c) dp[1][j+x] |= dp[0][j];
      }
    }
    swap(dp[0], dp[1]);
    for (int j{0}; j <= c; ++j) {
      dp[1][j] = 0;
    }
  }

  for (int i{c}; i >= 0; --i) {
    if (dp[0][i]) {
      cout << i << '\n';
      return 0;
    }
  }

  return 0;
}
