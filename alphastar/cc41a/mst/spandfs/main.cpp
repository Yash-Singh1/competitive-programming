#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  stack<int> s;
  vector<bool> visited(n);
  // handle collision...
  vector<pii> tr;
  visited[0] = 1;
  tr.reserve(n-1);
  s.push(0);
  while (s.size()) {
    int u = s.top();
    s.pop();
    for (auto &v: g[u]) {
      if (visited[v]) continue;
      s.push(v);
      tr.push_back({u, v});
      visited[v] = 1;
    }
  }

  for (auto &pp: tr) {
    cout << pp.first+1 << ' ' << pp.second+1 << '\n';
  }

  return 0;
}
