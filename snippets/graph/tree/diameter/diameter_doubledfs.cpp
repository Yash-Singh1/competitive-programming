#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // Initialize variables and graph
  vector<vector<int>> g(n);

  stack<pair<int,int>> s;
  s.push({0, -1});
  vector<int> dist(n);
  int a{0};
  while (s.size()) {
    int u = s.top().first;
    int p = s.top().second;
    s.pop();
    if (dist[u] > dist[a]) a = u;
    for (auto &v: g[u]) {
      if (v != p) {
        dist[v] = dist[u] + 1;
        s.push({v, u});
      }
    }
  }

  s.push({a, -1});
  vector<int> dist2(n);
  int b{a};
  while (s.size()) {
    int u = s.top().first;
    int p = s.top().second;
    s.pop();
    if (dist[u] > dist[b]) b = u;
    for (auto &v: g[u]) {
      if (v != p) {
        dist[v] = dist[u] + 1;
        s.push({v, u});
      }
    }
  }

  // Print length of diameter
  cout << dist[b] << "\n";

  return 0;
}
