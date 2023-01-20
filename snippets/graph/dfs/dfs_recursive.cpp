vector<bool> visited(N);
vector<vector<int>> graph(N);

void dfs(int u) {
  if (visited[u]) continue;
  visited[u] = 1;
  for (auto &v: graph[u]) {
    dfs(v);
  }
}
