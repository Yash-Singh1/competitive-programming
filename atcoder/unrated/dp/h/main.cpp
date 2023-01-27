#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w;
  cin >> h >> w;

  vector<vector<char>> grid(h+1, vector<char>(w+1));
  for (int i{0}; i <= h; ++i) {
    for (int j{0}; j <= w; ++j) {
      if (i == h || j == w) grid[i][j] = '#';
      else cin >> grid[i][j];
    }
  }

  vector<vector<int>> dp(h+1, vector<int>(w+1));
  dp[0][0] = 1;
  for (int i{0}; i < h; ++i) {
    for (int j{0}; j < w; ++j) {
      if (grid[i][j] == '#') continue;
      if (grid[i + 1][j] != '#') {
        dp[i + 1][j] += dp[i][j];
        dp[i + 1][j] %= MOD;
      }
      if (grid[i][j + 1] != '#') {
        dp[i][j + 1] += dp[i][j];
        dp[i][j + 1] %= MOD;
      }
    }
  }

  cout << dp[h - 1][w - 1] << "\n";

  return 0;
}
