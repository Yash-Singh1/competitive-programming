#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("ex.txt", "r", stdin);
  // freopen("ex.out", "w", stdout);

  ll n, m;
  cin >> n >> m;

  vector<vector<pii>> g(n);
  ll x, y, z;
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    g[x].push_back({y, z});
  }

  priority_queue<pii,vector<pii>,greater<pii>> q;
  vector<ll> dist(n, LLONG_MAX);
  dist[0] = 0;
  q.push({0, 0});
  while (!q.empty()) {
    ll d = q.top().first;
    ll u = q.top().second;
    q.pop();
    if (d != dist[u]) {
      continue;
    }
    for (auto &v: g[u]) {
      if (d + v.second < dist[v.first]) {
        q.push({dist[v.first] = d + v.second, v.first});
      }
    }
  }

  for (ll i{0}; i < n; ++i) {
    cout << dist[i] << " ";
  }
  cout << "\n";

  return 0;
}
