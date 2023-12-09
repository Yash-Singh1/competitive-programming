#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a;
  cin >> n >> m >> a; --a;

  vector<vector<pii>> g(n);
  int x, y, z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z; --x; --y;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  vector<int> dist(n, INT_MAX);
  dist[a] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, a});
  while (pq.size()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (d != dist[u]) continue;
    for (auto &v: g[u]) {
      if (d + v.second < dist[v.first]) {
        dist[v.first] = d + v.second;
        pq.push({dist[v.first], v.first});
      }
    }
  }

  for (int i{0}; i < n; ++i) {
    if (dist[i] == INT_MAX) cout << -1 << '\n';
    else cout << dist[i] << '\n';
  }

  return 0;
}
