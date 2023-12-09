#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<pii>> g(n);
  int x, y, z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z; --x; --y;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
  dist[0][k] = 0;
  priority_queue<piii, vector<piii>, greater<piii>> pq;
  pq.push({0, {k, 0}});
  while (pq.size()) {
    int d = pq.top().first;
    int left = pq.top().second.first;
    int u = pq.top().second.second;
    pq.pop();
    if (d != dist[u][left]) continue;
    for (auto &v: g[u]) {
      if (d + v.second < dist[v.first][left]) {
        dist[v.first][left] = d + v.second;
        pq.push({dist[v.first][left], {left, v.first}});
      }
      if (left > 0 && d < dist[v.first][left-1]) {
        dist[v.first][left-1] = d;
        pq.push({d, {left-1, v.first}});
      }
    }
  }

  int mn{INT_MAX};
  for (int i{0}; i <= k; ++i) {
    mn = min(mn, dist[n-1][i]);
  }

  cout << mn << '\n';

  return 0;
}
