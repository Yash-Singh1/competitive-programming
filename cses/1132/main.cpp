#include <bits/stdc++.h>

using namespace std;

vector<int> d1, d2;
vector<vector<int>> g;

void dfs(int u, int p) {
  int mxi{-1}, mx{-1};
  for (auto &v: g[u]) {
    if (v == p) continue;
    d2[v] = max(d2[v], d2[u] + 1);
    dfs(v, u);
    d1[u] = max(d1[u], d1[v] + 1);
    if (d1[v] + 2 > mx) {
      mxi = v;
      mx = d1[v] + 2;
    }
  }
  int mx2{-1};
  for (auto &v: g[u]) {
    if (v == p) continue;
    if (v != mxi) {
      mx2 = max(mx2, d1[v] + 2);
    }
  }
  for (auto &v: g[u]) {
    if (v == p) continue;
    if (v == mxi) {
      d2[v] = max(d2[v], mx2);
    } else {
      d2[v] = max(d2[v], mx);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  d1.resize(n); d2.resize(n); g.resize(n);
  int a, b;
  for (int i{1}; i < n; ++i) {
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0, -1);
  dfs(0, -1);

  for (int i{0}; i < n; ++i) {
    cout << max(d1[i], d2[i]) << " ";
  }
  cout << "\n";

  return 0;
}
