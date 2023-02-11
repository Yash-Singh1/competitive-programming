#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  ll n, m, k;
  cin >> n >> m >> k;

  vector<vector<pll>> g(n);
  ll a, b, c;
  for (ll i{0}; i < m; ++i) {
    cin >> a >> b >> c;
    --a; --b;
    g[a].push_back({b, c});
  }

  vector<multiset<ll>> dist(n);
  dist[0].insert(0);
  priority_queue<pll,vector<pll>,greater<pll>> q;
  q.push({0,0});
  while (q.size()) {
    ll u = q.top().second;
    ll d = q.top().first;
    q.pop();
    if (dist[u].find(d) == dist[u].end()) continue;
    for (auto &v: g[u]) {
      if (!((ll)dist[v.first].size() < k || d + v.second < *prev(dist[v.first].end()))) continue;
      dist[v.first].insert(d + v.second);
      if ((ll)dist[v.first].size() > k) {
        dist[v.first].erase(prev(dist[v.first].end()));
      }
      q.push({d + v.second, v.first});
      // if (*dist[v.first].begin() != f || dist[v.first].size() != sz) q.push({*dist[v.first].begin(), v.first});
    }
  }

  for (auto it = dist[n - 1].begin(); it != dist[n - 1].end(); it = next(it)) {
    cout << *it << (it != prev(dist[n - 1].end()) ? " " : "");
  }
  cout << "\n";

  return 0;
}
