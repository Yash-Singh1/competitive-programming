// Dijkstra optimal path, this can be done by working backwards from the end node to the start node
// Store flow of each node showing how many cows go through
// Multiply flow by (distance to end - t)
// Best path is the one with the highest number

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("shortcut.in", "r", stdin);
  freopen("shortcut.out", "w", stdout);

  ll n, m, t;
  cin >> n >> m >> t;

  vector<ll> flow(n);
  for (ll i{0}; i < n; ++i) cin >> flow[i];

  vector<vector<pll>> g(n);
  ll x, y, z;
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  vector<ll> dist(n, INT_MAX), p(n, -1);
  dist[0] = 0;
  priority_queue<pll, vector<pll>, greater<pll>> q;
  q.push({0, 0});
  while (q.size()) {
    ll u = q.top().second;
    ll d = q.top().first;
    q.pop();
    if (d != dist[u]) continue;
    for (auto &v: g[u]) {
      if (v.second + dist[u] < dist[v.first] || (dist[u] + v.second == dist[v.first] && u < p[v.first])) {
        p[v.first] = u;
        dist[v.first] = d + v.second;
        q.push({dist[v.first], v.first});
      }
    }
  }

  vector<ll> endflow(n);
  for (ll i{0}; i < n; ++i) {
    ll cur{i};
    while (cur != -1) {
      endflow[cur] += flow[i];
      cur = p[cur];
    }
  }

  ll ans{0};
  for (ll i{0}; i < n; ++i) {
    ans = max(ans, endflow[i] * (dist[i] - t));
  }
  cout << ans << "\n";

  return 0;
}
