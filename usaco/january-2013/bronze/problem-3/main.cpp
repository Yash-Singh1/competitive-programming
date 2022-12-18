#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("truth.in", "r", stdin);
  freopen("truth.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<pair<int,bool>> g[n];

  int x, y;
  char z;
  int color[n];
  bool visited[n];
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    g[x].push_back({y, z == 'L'});
    g[y].push_back({x, z == 'L'});
    for (int j{0}; j < n; ++j) {
      color[j] = -1;
      visited[j] = 0;
    }
    for (int j{0}; j < n; ++j) {
      if (visited[j]) continue;
      color[j] = 1;
      stack<int> s;
      s.push(j);
      while (!s.empty()) {
        int stop{s.top()};
        s.pop();
        if (visited[stop]) continue;
        visited[stop] = 1;
        for (auto &ne: g[stop]) {
          if (color[ne.first] == -1) {
            if (ne.second == 1) {
              color[ne.first] = 3 - color[stop];
            } else {
              color[ne.first] = color[stop];
            }
            s.push(ne.first);
          } else {
            if ((ne.second == 1 && color[ne.first] == color[stop]) || (ne.second == 0 && color[ne.first] != color[stop])) {
              cout << i << "\n";
              return 0;
            }
          }
        }
      }
    }
  }
  cout << m << "\n";

  return 0;
}
