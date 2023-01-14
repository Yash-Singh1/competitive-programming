#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, w;
  cin >> n >> w;

  vector<ll> itemw(n), itemv(n);
  for (ll i{0}; i < n; ++i) {
    cin >> itemw[i] >> itemv[i];
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(w + 1));
  ll ans{0};
  for (ll i{0}; i < n; ++i) {
    for (ll j{w}; j >= 0; --j) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j >= itemw[i]) {
        dp[i + 1][j - itemw[i]] = max(dp[i + 1][j - itemw[i]], dp[i][j] + itemv[i]);
      }
      ans = max(ans, dp[i + 1][j]);
    }
  }

  cout << ans << "\n";

  return 0;
}
