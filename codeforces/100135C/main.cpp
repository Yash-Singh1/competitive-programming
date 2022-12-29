#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("knight.in", "r", stdin);
  freopen("knight.out", "w", stdout);

  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> dp(n, vector<ll>(m));

  dp[0][0] = 1;
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < m; ++j) {
      if (j < m - 2 && i < n - 1) {
        dp[i + 1][j + 2] += dp[i][j];
      }
      if (i < n - 2 && j < m - 1) {
        dp[i + 2][j + 1] += dp[i][j];
      }
    }
  }

  cout << dp[n - 1][m - 1] << "\n";

  return 0;
}
