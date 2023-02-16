#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> d;
vector<int> depth;
vector<int> preorder, postorder;

int c{0};
void dfs(int u) {
  preorder[u] = c;
  ++c;
  d[depth[u]].push_back(preorder[u]);
  for (auto &v: g[u]) {
    depth[v] = depth[u] + 1;
    dfs(v);
  }
  postorder[u] = c;
  ++c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // Requires some smart way of offline querying
  // We need to process lower nodes first
  // However, we need to find a way to merge nodes as we move up the tree
  // This will require the maintainence of N BITs each of size N, so that isn't possible
  // If D_i < depth[U_i], ans = 0

  int n;
  cin >> n;
  g.resize(n);
  depth.resize(n);
  d.resize(n);
  preorder.resize(n);
  postorder.resize(n);

  int x;
  for (int i{1}; i < n; ++i) {
    cin >> x; --x;
    g[x].push_back(i);
  }

  dfs(0);
  int q;
  cin >> q;

  while (q--) {
    int u, de;
    cin >> u >> de;
    --u;
    cout << lower_bound(d[de].begin(), d[de].end(), postorder[u]) - lower_bound(d[de].begin(), d[de].end(), preorder[u]) << "\n";
  }

  return 0;
}
