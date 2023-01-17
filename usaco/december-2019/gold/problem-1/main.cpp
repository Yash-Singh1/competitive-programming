#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pump.in", "r", stdin);
  freopen("pump.out", "w", stdout);

  ll n, m;
  cin >> n >> m;

  vector<vector<pair<ll,pll>>> g(n);
  ll a, b, c, f;
  for (ll i{0}; i < m; ++i) {
    cin >> a >> b >> c >> f;
    --a; --b;
    g[a].push_back({b, {c, f}});
    g[b].push_back({a, {c, f}});
  }

  ll ans{0};
  for (ll i{1}; i <= 1000; ++i) {
    vector<ll> dist(n, 1e10);
    dist[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0,0});
    while (!q.empty()) {
      ll d = q.top().first;
      ll u = q.top().second;
      q.pop();
      if (d != dist[u]) continue;
      for (auto &v: g[u]) {
        if (v.second.second >= i && v.second.first + d < dist[v.first]) {
          dist[v.first] = v.second.first + d;
          q.push({v.second.first + d, v.first});
        }
      }
    }
    // cout << i << " " << dist[n - 1] << "\n";
    ans = max(ans, (ll)(((ld)i / dist[n - 1]) * (ll)1e6));
  }

  cout << ans << "\n";

  return 0;
}
