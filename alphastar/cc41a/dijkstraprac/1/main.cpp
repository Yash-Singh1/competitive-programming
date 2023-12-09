#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n, vector<int>(n, -1));
  int x, y, z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z; --x; --y;
    g[x][y] = g[x][y] < 0 ? z : min(g[x][y], z);
    g[y][x] = g[y][x] < 0 ? z : min(g[y][x], z);
  }

  vector<int> dist(n, INT_MAX), bk(n, -1), prevw(n, -1);
  dist[0] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, 0});
  while (pq.size()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (d != dist[u]) continue;
    for (int v{0}; v < n; ++v) {
      if (g[u][v] < 0) continue;
      if (d + g[u][v] < dist[v]) {
        dist[v] = d + g[u][v];
        bk[v] = u;
        prevw[v] = g[u][v];
        pq.push({dist[v], v});
      }
    }
  }

  int original{dist[n-1]};
  int ans{0}, cur{n-1};
  while (cur) {
    g[cur][bk[cur]] *= 2;
    g[bk[cur]][cur] *= 2;
    for (int i{0}; i < n; ++i) {
      dist[i] = INT_MAX;
    }
    dist[0] = 0;
    pq.push({0, 0});
    while (pq.size()) {
      int d = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      if (d != dist[u]) continue;
      for (int v{0}; v < n; ++v) {
        if (g[u][v] < 0) continue;
        if (d + g[u][v] < dist[v]) {
          dist[v] = d + g[u][v];
          pq.push({dist[v], v});
        }
      }
    }
    ans = max(ans, dist[n-1]);
    g[cur][bk[cur]] /= 2;
    g[bk[cur]][cur] /= 2;
    cur = bk[cur];
  }

  cout << ans-original << '\n';

  return 0;
}
