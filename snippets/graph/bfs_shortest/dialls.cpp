#include <bits/stdc++.h>

using namespace std;

const int MW = 10; // max weight

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int,int>>> g(n);
  int x, y, z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    g[x].push_back({y, z});
  }

  vector<queue<int>> b(MW+1); // buckets
  b[0].push(0);
  vector<int> dist(n);
  dist[0] = 0;
  while (true) {
    int w = 0;
    while (w <= MW && b[w].empty()) ++w;
    if (w == MW+1) break;
    int u = b[w].front();
    b[w].pop();
    for (auto &v: g[u]) {
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;
        b[v.second].push(v.first);
      }
    }
  }

  for (int i{0}; i < n; ++i) cout << dist[i] << " ";
  cout << "\n";

  return 0;
}
