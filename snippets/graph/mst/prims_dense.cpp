vector<vector<pair<int,int>>> g(n); // {destination vertex, weight}
vector<bool> selected(n);
vector<int> mn_edge(n, INT_MAX);
mn_edge[0] = 0;
int sm{0};
for (int i = 0; i < n; ++i)
{
  int u = -1;
  for (int j{0}; j < n; ++j) {
    if (!selected[j] && (u == -1 || mn_edge[j] < mn_edge[u])) u = j;
  }
  selected[u] = 1;
  if (mn_edge[u] == INT_MAX) {
    cout << "MST not possible\n";
    return 0;
  }
  sm += mn_edge[u];
  for (auto &v: g[u]) {
    mn_edge[u] = min(mn_edge[v.first], v.second);
  }
}
return sm;
