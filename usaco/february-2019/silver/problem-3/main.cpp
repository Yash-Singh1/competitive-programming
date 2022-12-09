#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<pair<int,int>> g[n];

  int x, y;
  char z;
  for (int i{0}; i < m; ++i) {
    cin >> z >> x >> y;
    --x; --y;
    if (z == 'S') {
      g[x].push_back({y, 1});
      g[y].push_back({x, 1});
    } else {
      g[x].push_back({y, 0});
      g[y].push_back({x, 0});
    }
  }

  int color[n];
  bool visited[n];
  for (int i{0}; i < n; ++i) {
    visited[i] = 0;
    color[i] = -1;
  }
  int tots{0};
  for (int i{0}; i < n; ++i) {
    if (visited[i]) continue;
    color[i] = 1;
    stack<int> s;
    s.push(i);
    while (!s.empty()) {
      int stop{s.top()};
      s.pop();
      visited[stop] = 1;
      for (auto &ne: g[stop]) {
        if (color[ne.first] == -1) {
          if (ne.second == 1) {
            color[ne.first] = color[stop];
          } else {
            color[ne.first] = 3 - color[stop];
          }
          s.push(ne.first);
        } else {
          if ((ne.second == 1 && color[ne.first] != color[stop]) || (ne.second == 0 && color[ne.first] == color[stop])) {
            cout << 0 << "\n";
            return 0;
          }
        }
      }
    }
    ++tots;
  }

  cout << 1;
  for (int i{0}; i < tots; ++i) {
    cout << 0;
  }
  cout << "\n";

  return 0;
}
