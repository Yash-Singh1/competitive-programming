#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  vector<int> indeg(n);
  vector<vector<int>> g(n);
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    ++indeg[y];
  }

  queue<int> q;
  for (int i{0}; i < n; ++i) {
    if (!indeg[i]) q.push(i);
  }

  vector<int> ans;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v: g[u]) {
      --indeg[v];
      if (!indeg[v]) q.push(v);
    }
    ans.push_back(u + 1);
  }

  for (auto &ansp: ans) cout << ansp << " ";
  cout << "\n";
}
