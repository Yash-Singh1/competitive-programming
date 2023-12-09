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
    cin >> x >> y >> z; --x; --y;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  vector<int> dist(n, INT_MAX);
  vector<vector<int>> bk(n);
  dist[0] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, 0});
  while (pq.size()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (d != dist[u]) continue;
    for (auto &v: g[u]) {
      if (d + v.second < dist[v.first]) {
        dist[v.first] = d + v.second;
        bk[v.first].clear();
        bk[v.first].push_back(u);
        pq.push({dist[v.first], v.first});
      } else if (d + v.second == dist[v.first]) {
        bk[v.first].push_back(u);
      }
    }
  }

  queue<int> q;
  vector<int> visited(n);
  q.push(n-1);
  while (q.size()) {
    int u = q.front();
    q.pop();
    visited[u] = 1;
    for (auto &v: bk[u]) {
      if (!visited[v]) q.push(v);
    }
  }

  for (int i{0}; i < n; ++i) {
    if (visited[i]) cout << i+1 << ' ';
  }
  cout << '\n';

  return 0;
}
