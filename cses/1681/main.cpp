#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> g(n);
  vector<vector<ll>> tg(n);
  vector<ll> indeg(n);
  ll x, y;
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    tg[y].push_back(x);
    ++indeg[y];
  }

  vector<ll> dp(n, -1);
  dp[0] = 1;
  queue<ll> q;
  for (ll i{0}; i < n; ++i) {
    if (!indeg[i] || i == 0) q.push(i);
  }

  while (!q.empty()) {
    ll u = q.front();
    q.pop();
    for (auto &v: g[u]) {
      --indeg[v];
      if (!indeg[v]) q.push(v);
    }
    if (u != 0) {
      dp[u] = 0;
      for (auto &v: tg[u]) {
        // cout << u << " " << v << "\n";
        if (dp[v] != -1) {
          dp[u] += dp[v];
          dp[u] %= MOD;
        }
      }
    }
  }

  if (dp[n - 1] < 0) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << dp[n - 1] << "\n";
  }

  return 0;
}
