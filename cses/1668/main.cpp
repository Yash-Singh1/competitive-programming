#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int color[n];
  for (int i{0}; i < n;++i) {
    color[i] = -1;
  }

  vector<int> g[n];
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  stack<int> s;
  bool visited[n];
  for (int i{0}; i < n; ++i) {
    visited[i] = 0;
  }
  for (int j{0}; j < n; ++j) {
    if (visited[j]) continue;
    s.push(j);
    color[j] = 0;
    while (!s.empty()) {
      int stop{s.top()};
      s.pop();
      visited[stop] = 1;
      for (auto &ne: g[stop]) {
        if (color[ne] == color[stop]) {
          cout << "IMPOSSIBLE\n";
          return 0;
        } else if (color[ne] == -1) {
          color[ne] = 1 - color[stop];
        }
        if (!visited[ne]) {
          s.push(ne);
        }
      }
    }
  }

  for (int i{0}; i < n; ++i) {
    cout << (color[i]+1) << " ";
  }
  cout << "\n";

  return 0;
}
