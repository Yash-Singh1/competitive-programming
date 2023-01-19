#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const ll MOD = (ll)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<vector<pll>> g(n);
  ll a, b, c;
  for (ll i{0}; i < m; ++i) {
    cin >> a >> b >> c;
    --a; --b;
    g[a].push_back({b, c});
  }

  vector<ll> dist(n, 1e15), paths(n), mnl(n, 1e15), mxl(n);
  priority_queue<pll, vector<pll>, greater<pll>> q;
  q.push({0, 0});
  dist[0] = 0; paths[0] = 1; mnl[0]=0;
  while (q.size()) {
    ll u = q.top().second;
    ll d = q.top().first;
    q.pop();
    if (d != dist[u]) continue;
    for (auto &v: g[u]) {
      if (v.second + d < dist[v.first]) {
        paths[v.first] = 0;
        dist[v.first] = v.second + d;
        mnl[v.first] = 1e15;
        mxl[v.first] = 0;
        q.push({dist[v.first], v.first});
      }
      if (v.second + d == dist[v.first]) {
        paths[v.first] += paths[u];
        paths[v.first] %= MOD;
        mnl[v.first] = min(mnl[v.first], mnl[u] + 1);
        mxl[v.first] = max(mxl[v.first], mxl[u] + 1);
      }
    }
  }

  cout << dist[n - 1] << " " << paths[n - 1] << " " << mnl[n - 1] << " " << mxl[n - 1] << "\n";

  return 0;
}
