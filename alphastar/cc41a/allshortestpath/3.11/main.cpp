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

  if (m == n - 1) {
    stack<pii> s;
    vector<int> vis(n);
    s.push({0, -1});
    while (s.size()) {
      int u{s.top().first};
      int up{s.top().second};
      s.pop();
      vis[u] = 1;
      for (auto &v: g[u]) {
        if (v != up) {
          if (!vis[v]) {
            s.push({v, u});
          } else {
            cout << "NOT TREE\n";
            return 0;
          }
        }
      }
    }
    cout << "TREE\n";
  } else {
    cout << "NOT TREE\n";
  }

  return 0;
}
