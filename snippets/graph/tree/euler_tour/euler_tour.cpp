// Find sum of values in a subtree

#include <bits/stdc++.h>

using namespace std;

vector<int> sz;

void sz(int u, int p) {
  sz[u] = 1;
  for (auto &v: g[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> val(n);
  vector<vector<int>> g(n);

  // Initialize variables...

  stack<pair<int,int>> s;
  vector<int> tour;
  s.push({0, -1});
  while (s.size()) {
    int u = s.top().first;
    int p = s.top().second;
    s.pop();
    tour.push_back(val[u]);
    for (auto &v: g[u]) {
      if (v != p) {
        s.push({u, v});
      }
    }
  }
  sz.resize(n);

  for (int i{1}; i < n; ++i) {
    tour[i] += tour[i - 1];
  }

  // To calculate value of subtree of node u
  // tour[u + sz[u] - 1] - (u ? tour[u - 1] : 0)

  return 0;
}
