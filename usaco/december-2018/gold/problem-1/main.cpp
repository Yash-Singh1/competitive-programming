#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("dining.in", "r", stdin);
  freopen("dining.out", "w", stdout);

  // Find optimal path for each vertex
  // Add negative edge from haybale to Nth pasture, and check if Dijkstra improves

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<pii>> g(n+1), tg(n);
  int x, y, z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  vector<int> dist(n, INT_MAX);
  dist[n - 1] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, n - 1});
  while (!q.empty()) {
    int u = q.top().second;
    int d = q.top().first;
    q.pop();
    if (dist[u] != d) continue;
    for (auto &v: g[u]) {
      if (d + v.second < dist[v.first]) {
        dist[v.first] = d + v.second;
        q.push({dist[v.first], v.first});
      }
    }
  }

  vector<int> haybales(n, -1);
  for (int i{0}; i < k; ++i) {
    cin >> x >> y;
    --x;
    haybales[x] = max(haybales[x], y);
  }

  for (int i{0}; i < n; ++i) {
      g[n].push_back({i, dist[i] - haybales[i]});
  }

  vector<int> dist2(n+1, INT_MAX);
  dist2[n] = 0;
  q.push({0, n});
  while (!q.empty()) {
    int u = q.top().second;
    int d = q.top().first;
    q.pop();
    if (dist2[u] != d) continue;
    for (auto &v: g[u]) {
      if (v.second + d < dist2[v.first]) {
        dist2[v.first] = v.second + d;
        q.push({dist2[v.first], v.first});
      }
    }
  }

  for (int i{0}; i < n-1; ++i) {
    // cout << dist[i] << " " << dist2[i] << "\n";
    cout << (dist2[i] <= dist[i]) << "\n";
  }

  return 0;
}
