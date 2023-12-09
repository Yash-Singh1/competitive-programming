#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

struct Edge {
  int s, w, f;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, x;
  cin >> n >> m;
  vector<vector<Edge>> g(n);

  Edge y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y.s >> y.w >> y.f;
    --x; --y.s;
    g[x].push_back(y);
    int c{x};
    x = y.s;
    y.s = c;
    g[x].push_back(y);
  }

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> dist(n);
  int ans{0};
  for (int i{1}; i <= 1000; ++i) {
    for (int j{0}; j < n; ++j) {
      dist[j] = INT_MAX;
    }
    dist[0] = 0;
    pq.push({0, 0});
    while (pq.size()) {
      int d = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      if (d != dist[u]) continue;
      for (auto &v: g[u]) {
        if (v.f >= i && v.w + d < dist[v.s]) {
          dist[v.s] = v.w + d;
          pq.push({dist[v.s], v.s});
        }
      }
    }
    ans = max(ans, (i*1000000)/dist[n-1]);
  }

  cout << ans << '\n';

  return 0;
}
