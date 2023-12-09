#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, b;
  cin >> n >> m >> a >> b; --a; --b;

  vector<vector<pii>> g(n);
  int x, y, z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z; --x; --y;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  vector<int> dist(n, INT_MAX), bk(n, -1);
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
        bk[v.first] = u;
        pq.push({dist[v.first], v.first});
      }
    }
  }

  cout << dist[b] << ' ';
  int cur{b};
  vector<int> path;
  path.reserve(n);
  while (cur != a) {
    path.push_back(cur);
    cur = bk[cur];
  }

  path.push_back(a);
  reverse(path.begin(), path.end());
  cout << path.size() << '\n';
  for (auto &el: path) {
    cout << el+1 << '\n';
  }

  return 0;
}
