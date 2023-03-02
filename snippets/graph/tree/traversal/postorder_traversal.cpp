#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(n);
vector<int> postorder;

void dfs(int u, int p) {
  for (auto &v: g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  postorder.push_back(u);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // Initialize variables...

  dfs(0, -1);

  // Print out or use postorder traversal...

  return 0;
}
