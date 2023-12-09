#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int f, s, w;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int d, m1, n, m2, s;
  cin >> d >> m1 >> n >> m2 >> s;
  --s;

  vector<Edge> edge(m1+m2);
  for (int i{0}; i < m1; ++i) {
    cin >> edge[i].f >> edge[i].s; edge[i].w = -d;
    --edge[i].f; --edge[i].s;
  }

  for (int i{m1}; i < m1+m2; ++i) {
    cin >> edge[i].f >> edge[i].s >> edge[i].w;
    edge[i].w -= d;
    --edge[i].f; --edge[i].s;
  }

  vector<int> dist(n, INT_MAX);
  dist[s] = 0;
  for (int i{0}; i < n-1; ++i) {
    for (auto &e: edge) {
      if (dist[e.f] == INT_MAX) continue;
      if (dist[e.s] > dist[e.f] + e.w) {
        dist[e.s] = dist[e.f] + e.w;
      }
    }
  }

  for (auto &e: edge) {
    if (dist[e.s] > dist[e.f] + e.w) {
      cout << "-1\n";
      return 0;
    }
  }

  int mn{INT_MAX};
  for (int i{0}; i < n; ++i) {
    mn = min(mn, dist[i]);
  }

  cout << (-mn) + d << '\n';

  return 0;
}
