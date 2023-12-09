#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<pii>> g(n);
  int x, y, z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i{0}; i < n; ++i) {
    dist[i][i] = 0;
    pq.push({0, i});
    while (pq.size()) {
      int d = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      if (d != dist[i][u]) continue;
      for (auto &v: g[u]) {
        if (d + v.second < dist[i][v.first]) {
          dist[i][v.first] = d + v.second;
          pq.push({dist[i][v.first], v.first});
        }
      }
    }
  }

  while (k--) {
    cin >> x >> y;
    --x; --y;
    if (dist[x][y] == INT_MAX) {
      cout << "-1\n";
    } else {
      cout << dist[x][y] << '\n';
    }
  }

  return 0;
}
