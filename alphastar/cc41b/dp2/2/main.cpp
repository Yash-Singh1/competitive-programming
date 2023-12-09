#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t;
  cin >> n >> m >> t;

  vector<vector<char>> grid(n, vector<char>(m));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  --x1; --y1; --x2; --y2;

  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(t+1, 0)));
  dp[x1][y1][0] = 1;
  int mx[4] {0, 0, 1, -1};
  int my[4] {1, -1, 0, 0};
  for (int k{0}; k < t; ++k) {
    for (int i{0}; i < n; ++i) {
      for (int j{0}; j < m; ++j) {
        if (!dp[i][j][k]) continue;
        for (int d{0}; d < 4; ++d) {
          if (i + mx[d] < 0 || i + mx[d] >= n || j + my[d] < 0 || j + my[d] >= m) continue;
          if (grid[i + mx[d]][j + my[d]] == '*') continue;
          dp[i+mx[d]][j+my[d]][k+1] += dp[i][j][k];
        }
      }
    }
  }

  cout << dp[x2][y2][t] << '\n';

  // int ans = 0;
  // for (int i{0}; i <= t; ++i) {
  //   ans += dp[x2][y2][i];
  // }

  // cout << ans << '\n';

  return 0;
}
