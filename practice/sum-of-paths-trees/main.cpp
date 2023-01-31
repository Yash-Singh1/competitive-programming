#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<int> subtree(1000);
vector<vector<int>> g(1000);

int dfs(int u, int p) {
  int sm{1};
  for (auto &v: g[u]) {
    if (v == p) continue;
    sm += dfs(v, u);
  }
  subtree[u] = sm;
  return sm;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(0, -1);

  int ans{0};
  for (int i{0}; i < n; ++i) {
    for (auto &v: g[i]) {
      ans += min(subtree[i], subtree[v]) * (n - min(subtree[i], subtree[v]));
    }
  }

  ans >>= 1;
  cout << ans << "\n";

  return 0;
}
