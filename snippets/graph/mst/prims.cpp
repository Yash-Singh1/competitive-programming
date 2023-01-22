vector<vector<int>> g(n);
vector<bool> selected(n);

priority_queue<pii, vector<int>, greater<int>> q;
q.push({0, 0});
int ans{0};
while (!q.empty()) {
  int u = q.top().second;
  int w = q.top().first;
  q.pop();
  if (selected[u]) continue;
  selected[u] = 1;
  ans += w;
  for (auto &v: g[u]) {
    if (!selected[v.first]) {
      q.push({v.second, v.first});
    }
  }
}
