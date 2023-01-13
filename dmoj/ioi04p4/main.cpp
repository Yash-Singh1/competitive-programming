#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, h, n;
  cin >> w >> h >> n;

  vector<pair<int,int>> expected(n);
  vector<vector<int>> dp(w + 1, vector<int>(h + 1, INT_MAX));
  for (int i{0}; i < n; ++i) {
    cin >> expected[i].first >> expected[i].second;
    dp[expected[i].first][expected[i].second] = 0;
  }
  dp[0][0] = 0;

  for (int j{0}; j <= w; ++j) {
    for (int k{0}; k <= h; ++k) {
      dp[j][k] = min(dp[j][k], j * k);
      for (int x{j - 1}; x > 0; --x) {
        dp[j][k] = min(dp[j][k], dp[x][k] + dp[j - x][k]);
      }
      for (int y{k - 1}; y > 0; --y) {
        dp[j][k] = min(dp[j][k], dp[j][y] + dp[j][k - y]);
      }
    }
  }

  cout << dp[w][h] << "\n";

  return 0;
}
