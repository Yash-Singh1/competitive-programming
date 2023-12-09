#include <bits/stdc++.h>

using namespace std;

typedef pair<pair<int,int>,pair<int,int>> Coaster;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int l, n, b;
  cin >> l >> n >> b;

  vector<Coaster> c(n);
  for (int i{0}; i < n; ++i) {
    cin >> c[i].first.first >> c[i].first.second >> c[i].second.first >> c[i].second.second;
  }
  sort(c.begin(), c.end());

  vector<vector<int>> dp(l+1, vector<int>(b+1, -1));
  dp[0][b] = 0;
  for (int i{0}; i < l; ++i) {
    for (int j{b}; j >= 0; --j) {
      if (dp[i][j] >= 0) {
        auto it = lower_bound(c.begin(), c.end(), Coaster{{i, -1}, {-1, -1}});
        for (auto iti = it; iti != c.end() && iti->first.first == i; iti = next(iti)) {
          if (iti->second.second > j) continue;
          dp[i + iti->first.second][j - iti->second.second] = max(dp[i + iti->first.second][j - iti->second.second], dp[i][j] + iti->second.first);
        }
      }
    }
  }

  // for (int i{0}; i <= n; ++i) {
  //   for (int j{0}; j <= b; ++j) {
  //     cout << (dp[i][j] < 10 && dp[i][j] >= 0 ? "0" : "") << dp[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';

  int mx{-1};
  for (int i{0}; i <= b; ++i) {
    mx = max(mx, dp[l][i]);
  }

  cout << mx << '\n';

  return 0;
}
