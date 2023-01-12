#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> g[n];
  vector<int> in(n);
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    ++in[y];
  }

  queue<int> q;
  for (int i{0}; i < n; ++i) {
    if (in[i] == 0) {
      q.push(i);
    }
  }

  vector<int> ans(n);
  int j{0};
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v: g[u]) {
      --in[v];
      if (in[v] == 0) q.push(v);
    }
    ans[j] = u + 1;
    ++j;
  }

  if (j != n) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  for (auto &anse: ans) cout << anse << " ";
  cout << '\n';

  return 0;
}
