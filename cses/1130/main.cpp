#include <bits/stdc++.h>

using namespace std;

vector<int> dp1, dp2;
vector<vector<int>> g;

void dfs(int u, int p) {
  int mxs{0};
  for (auto &v: g[u]) {
    if (v != p) {
      dfs(v, u);
      mxs += max(dp1[v], dp2[v]);
    }
  }
  for (auto &v: g[u]) {
    if (v != p) {
      dp1[u] = max(dp1[u], mxs - max(dp1[v], dp2[v]) + dp2[v] + 1);
    }
  }
  dp2[u] = mxs;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  g.resize(n);
  dp1.resize(n);
  dp2.resize(n);
  int a, b;
  for (int i{1}; i < n; ++i) {
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0, -1);
  cout << max(dp1[0], dp2[0]) << "\n";

  return 0;
}
