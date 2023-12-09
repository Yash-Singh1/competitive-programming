#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pii>> g(n);
  int x, y, z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  priority_queue<pair<pii,int>, vector<pair<pii,int>>, greater<pair<pii,int>>> pq;
  pq.push({{0, 0}, -1});
  int wtot{0};
  vector<pii> e;
  vector<bool> vis(n, 0);
  e.reserve(n-1);
  while (pq.size()) {
    int w = pq.top().first.first;
    int u = pq.top().first.second;
    int p = pq.top().second;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    if (p >= 0) e.push_back({u, p});
    wtot += w;
    for (auto &v: g[u]) {
      if (!vis[v.first]) {
        pq.push({{v.second, v.first}, u});
      }
    }
  }

  cout << wtot << '\n';
  for (auto &ed: e) {
    cout << ed.first+1 << ' ' << ed.second+1 << '\n';
  }

  return 0;
}
