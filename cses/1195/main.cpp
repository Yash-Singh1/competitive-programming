#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<vector<pll>> g(n), tg(n);
  vector<pair<pll,ll>> adj(m);
  ll x, y, z;
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    g[x].push_back({y, z});
    tg[y].push_back({x, z});
    adj[i] = {{x, y}, z};
  }

  priority_queue<pll,vector<pll>,greater<pll>> q;
  q.push(make_pair(0, 0));
  vector<ll> dist(n, (ll)1e15);
  dist[0] = 0;
  while (!q.empty()) {
    ll u = q.top().second;
    ll d = q.top().first;
    q.pop();
    if (d != dist[u]) continue;
    for (auto &v: g[u]) {
      if (d + v.second < dist[v.first]) {
        dist[v.first] = v.second + d;
        q.push(make_pair(v.second + d, v.first));
      }
    }
  }

  priority_queue<pll,vector<pll>,greater<pll>> q2;
  q2.push(make_pair(0, n - 1));
  vector<ll> dist2(n, (ll)1e15);
  dist2[n - 1] = 0;
  while (!q2.empty()) {
    ll u = q2.top().second;
    ll d = q2.top().first;
    q2.pop();
    if (d != dist2[u]) continue;
    for (auto &v: tg[u]) {
      if (d + v.second < dist2[v.first]) {
        dist2[v.first] = v.second + d;
        q2.push(make_pair(v.second + d, v.first));
      }
    }
  }

  ll price{(ll)1e15};
  for (int i{0}; i < m; ++i) {
    price = min(price, dist[adj[i].first.first] + dist2[adj[i].first.second] + (adj[i].second / 2));
    // price = min(price, dist[adj[i].first.second] + dist2[adj[i].first.first] + (adj[i].second / 2));
  }

  cout << price << "\n";

  return 0;
}
