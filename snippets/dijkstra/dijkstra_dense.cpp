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
  }

  vector<bool> processed(n);
  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  for (int i{0}; i < n; ++i) {
    int u{-1};
    for (int j{0}; j < n; ++j) {
      if (!processed[j] && (u == -1 || dist[j] < dist[u])) {
        u = j;
      }
    }
    if (dist[u] == INT_MAX) {
      break;
    }
    processed[u] = 1;
    for (auto &v: g[u]) {
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;
      }
    }
  }

  for (int i{0}; i < n; ++i) {
    cout << dist[i] << " ";
  }
  cout << "\n";

  return 0;
}
