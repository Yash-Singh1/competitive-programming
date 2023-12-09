#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> dist(n-1);
  vector<pair<int,int>> point(n);
  int z, d;
  for (int i{0}; i < n; ++i) {
    cin >> point[i].first >> point[i].second;
    if (i) {
      dist[i-1] = abs(z - point[i].first) + abs(d - point[i].second);
    }
    z = point[i].first;
    d = point[i].second;
  }

  vector<vector<int>> dp(n, vector<int>(k+1));
  dp[0][k] = 0;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= k; ++j) {
      if (i) {
      dp[i][j] = dp[i-1][j] + dist[i-1];
      for (int l{0}; l < i && l <= k-j; ++l) {
        dp[i][j] = min(dp[i][j], dp[i-l-1][j+l] + abs(point[i].first - point[i-l-1].first) + abs(point[i].second - point[i-l-1].second));
      }
      }
      // cout << dp[i][j] << ' ';
    }
    // cout << '\n';
  }

  int mn{INT_MAX};
  for (int i{0}; i <= k; ++i) {
    mn = min(mn, dp[n-1][i]);
  }
  cout << mn << '\n';

  return 0;
}
