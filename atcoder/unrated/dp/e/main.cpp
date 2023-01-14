// Another technique is to reverse the idea of Knapsack
// Instead of storing max val for weight store min weight for val

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

  vector<vector<ll>> dp(n + 1, vector<ll>(100001, LLONG_MAX));
  dp[0][0] = 0;
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j <= 100000; ++j) {
      if (dp[i][j] < LLONG_MAX) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j + itemv[i]] = min(dp[i + 1][j + itemv[i]], dp[i][j] + itemw[i]);
      }
    }
  }

  for (ll i{100000}; i >= 0; --i) {
    if (dp[n][i] <= w) {
      cout << i << "\n";
      return 0;
    }
  }

  return 0;
}
