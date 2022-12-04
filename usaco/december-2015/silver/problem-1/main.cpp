#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lightson.in", "r", stdin);
  freopen("lightson.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  pair<int,int> a[n][n];
  bool lit[n][n];
  bool visited[n][n];
  int x, y;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      lit[i][j] = 0;
      visited[i][j] = 0;
      a[i][j] = {-1, -1};
    }
  }
  lit[0][0] = 1;

  vector<pair<int,int>> g[n][n];

  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    cin >> a[x][y].first >> a[x][y].second;
    --a[x][y].first; --a[x][y].second;
    g[x][y].push_back({a[x][y].first, a[x][y].second});
  }

  int dx[4] {0, 0, 1, -1};
  int dy[4] {1, -1, 0, 0};
  stack<pair<int,int>> s;
  s.push({0, 0});
  while (!s.empty()) {
    pair<int,int> stop{s.top()};
    s.pop();
    if (visited[stop.first][stop.second]) continue;
    visited[stop.first][stop.second] = 1;
    for (auto &p: g[stop.first][stop.second]) {
      if (lit[p.first][p.second]) continue;
      lit[p.first][p.second] = 1;
      bool can{0};
      for (int j{0}; j < 4; ++j) {
        if (p.first + dx[j] < 0 || p.first + dx[j] >= n) continue;
        if (p.second + dy[j] < 0 || p.second + dy[j] >= n) continue;
        if (visited[p.first + dx[j]][p.second + dy[j]]) {
          can = 1;
          break;
        }
      }
      if (can) {
        s.push({p.first, p.second});
      }
    }
    for (int j{0}; j < 4; ++j) {
      if (stop.first + dx[j] < 0 || stop.first + dx[j] >= n) continue;
      if (stop.second + dy[j] < 0 || stop.second + dy[j] >= n) continue;
      if (visited[stop.first + dx[j]][stop.second + dy[j]] || !lit[stop.first + dx[j]][stop.second + dy[j]]) continue;
      s.push({stop.first + dx[j], stop.second + dy[j]});
    }
  }

  int reach{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (lit[i][j]) ++reach;
    }
  }
  cout << reach << "\n";

  // for (int i{0}; i < n; ++i) {
  //   for (int j{0}; j < n; ++j) {
  //     cout << visited[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  return 0;
}
