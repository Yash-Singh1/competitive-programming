// Recognize the points as a graph with the values on the y-axis and index on x-axis
// Need to count possible graphs using 2D, since this is 2D graph.
// We can only consider fixed points if a fixed point only is possible

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);
  for (ll i{0}; i < n; ++i) cin >> a[i];

  vector<vector<ll>> dp(n, vector<ll>(m + 1));
  ll ans{0};
  for (ll i{0}; i < n; ++i) {
    for (ll j{1}; j <= m; ++j) {
      if (i == 0) {
        if (a[i] == 0) dp[i][j] = 1;
        else if (a[i] == j) dp[i][j] = 1;
      }
      else if (a[i] != 0) {
        if (j == a[i]) {
          for (ll s{max(1LL, a[i] - 1)}; s <= a[i] + 1 && s <= m; ++s) {
            dp[i][j] += dp[i - 1][s];
            dp[i][j] %= MOD;
          }
        }
      }
      else {
        for (ll s{max(1LL, j - 1)}; s <= j + 1 && s <= m; ++s) {
          dp[i][j] += dp[i - 1][s];
          dp[i][j] %= MOD;
        }
      }
      if (i == n - 1) {
        ans += dp[i][j];
        ans %= MOD;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
