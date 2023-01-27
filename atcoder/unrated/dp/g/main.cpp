#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> g(n);
  vector<int> in(n);
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    ++in[y];
  }

  queue<int> q;
  vector<int> dist(n);
  for (int i{0}; i < n; ++i) {
    if (!in[i]) {
      dist[i] = 0;
      q.push(i);
    }
  }

  while (q.size()) {
    int u = q.front();
    q.pop();
    for (auto &v: g[u]) {
      --in[v];
      dist[v] = max(dist[v], dist[u] + 1);
      if (!in[v]) {
        q.push(v);
      }
    }
  }

  int ans{0};
  for (auto &distance: dist) {
    ans = max(ans, distance);
  }

  cout << ans << "\n";

  return 0;
}
