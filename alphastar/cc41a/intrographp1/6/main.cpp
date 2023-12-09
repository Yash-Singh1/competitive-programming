#include <bits/stdc++.h>

using namespace std;

vector<int> visited;
vector<vector<int>> g;
vector<int> t, l;
int timern{0};
vector<int> br;

int dfs(int u, int p) {
  visited[u] = 1;
  int children = 0;
  t[u] = timern++;
  l[u] = t[u];
  for (auto &ne: g[u]) {
    if (ne == p) continue;
    if (!visited[ne]) {
      dfs(ne, u);
      ++children;
      if (t[u] <= l[ne] && u) {
        br.push_back(u);
      }
      l[u] = min(l[u], l[ne]);
    } else {
      l[u] = min(l[u], t[ne]);
    }
  }

  return children;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, x, y;
  cin >> n >> m;

  visited.resize(n);
  t.resize(n);
  l.resize(n);
  g.resize(n);

  for (int i{0}; i < m; ++i) {
    cin >> x >> y; --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  if (dfs(0, -1) > 1){
    br.push_back(0);
  }

  for (int i{0}; i < n; ++i) {
    if (!visited[i]) {
      cout << "0\n";
      return 0;
    }
  }

  sort(br.begin(), br.end());

  cout << br.size() << '\n';
  for (auto &bridge: br) {
    cout << bridge+1 << '\n';
  }

  return 0;
}
