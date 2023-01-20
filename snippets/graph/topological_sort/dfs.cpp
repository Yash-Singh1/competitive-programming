vector<int> ans;
vector<bool> visited;
vector<vector<int>> g(n);

void dfs(int u) {
  if (visited[u]) return;
  visited[u] = 1;
  for (auto &v: g[u]) {
    dfs(v);
  }
  ans.push_back(u);
}

int main() {
  // Take in input...
  // Initialize variables...

  for (int i{0}; i < n; ++i) {
    if (!visited[i]) dfs(i);
  }

  reverse(ans.begin(), ans.end());

  // Output ans
}
