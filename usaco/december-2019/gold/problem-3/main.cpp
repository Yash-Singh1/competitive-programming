#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cowmbat.in", "r", stdin);
  freopen("cowmbat.out", "w", stdout);

  ll n, m, k;
  cin >> n >> m >> k;

  ll s[n];
  char x;
  for (ll i{0}; i < n; ++i) {
    cin >> x;
    s[i] = x - 'a';
    assert(s[i] < m);
  }

  vector<vector<ll>> cost(m, vector<ll>(m));
  for (ll i{0}; i < m; ++i) {
    for (ll j{0}; j < m; ++j) {
      cin >> cost[i][j];
    }
  }

  for (ll k{0}; k < m; ++k) {
    for (ll i{0}; i < m; ++i) {
      for (ll j{0}; j < m; ++j) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }

  vector<vector<ll>> p(m, vector<ll>(n));
  for (ll i{0}; i < m; ++i) {
    for (ll j{0}; j < n; ++j) {
      p[i][j] = (j == 0 ? 0 : p[i][j - 1]) + cost[s[j]][i];
    }
  }

  vector<vector<ll>> dp(n+1, vector<ll>(m, INT_MAX));
  vector<ll> dpmin(n+1, INT_MAX);
  dpmin[0] = 0;
  for (ll i{1}; i <= n; ++i) {
    for (ll j{0}; j < m; ++j) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost[s[i - 1]][j]);
      if (i >= k) dp[i][j] = min(dp[i][j], dpmin[i - k] + (p[j][i - 1] - (i == k ? 0 : p[j][i - k - 1])));
      dpmin[i] = min(dpmin[i], dp[i][j]);
    }
  }

  cout << dpmin[n] << "\n";

  return 0;
}
