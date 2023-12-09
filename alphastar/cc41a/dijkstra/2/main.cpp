#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> m >> n;

  vector<int> starts(3);
  for (int i{0}; i < 3; ++i) {
    cin >> starts[i]; --starts[i];
  }

  vector<vector<pii>> g(n);
  int x, y, z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z; --x; --y;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  vector<vector<int>> dist(n, vector<int>(3, INT_MAX));
  for (int i{0}; i < 3; ++i) {
    dist[starts[i]][i] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, starts[i]});
    while (pq.size()) {
      int d = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      if (d != dist[u][i]) continue;
      for (auto &v: g[u]) {
        if (d + v.second < dist[v.first][i]) {
          dist[v.first][i] = d + v.second;
          pq.push({dist[v.first][i], v.first});
        }
      }
    }
  }

  cout << min(dist[starts[1]][0] + dist[starts[2]][1], dist[starts[2]][0] + dist[starts[1]][2]) << '\n';

  return 0;
}
