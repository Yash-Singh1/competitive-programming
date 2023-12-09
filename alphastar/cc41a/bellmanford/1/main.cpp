#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int f, s, w;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<Edge> e(m);
  for (int i{0}; i < m; ++i) {
    cin >> e[i].f >> e[i].s >> e[i].w;
    --e[i].f; --e[i].s;
  }

  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  for (int i{0}; i < n-1; ++i) {
    for (auto &edge: e) {
      if (dist[edge.f] == INT_MAX) continue;
      if (dist[edge.s] > dist[edge.f] + edge.w) {
        dist[edge.s] = dist[edge.f] + edge.w;
      }
    }
  }

  for (auto &edge: e) {
    if (dist[edge.s] > dist[edge.f] + edge.w) {
      cout << "moo\n";
      return 0;
    }
  }

  for (int i{0}; i < n; ++i) {
    cout << dist[i] << '\n';
  }

  return 0;
}
