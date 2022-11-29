#include <bits/stdc++.h>

using namespace std;

int dx[4] {1, -1, 0, 0};
int dy[4] {0, 0, 1, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("ccski.in", "r", stdin);
  freopen("ccski.out", "w", stdout);

  int n, m;
  int waypoints{0};

  cin >> n >> m;
  int grid[n][m];
  pair<int,int> waypoint[n*m];

  int x;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> x;
      if (x == 1) {
        waypoint[waypoints] = {i,j};
      }
      waypoints += x;
    }
  }

  int l{0}, r{(int)1e9}, ans{-1};
  bool visited[n][m];
  while (l <= r) {
    int mid{(l+r)/2};
    stack<pair<int,int>> s;
    for (int i{0}; i < n; ++i) {
      for (int j{0}; j < m; ++j) {
        visited[i][j] = 0;
      }
    }
    s.push(waypoint[0]);
    while (!s.empty()) {
      pair<int,int> tp{s.top()};
      s.pop();
      if (visited[tp.first][tp.second]) {
        continue;
      }
      visited[tp.first][tp.second] = 1;
      for (int k{0}; k < 4; ++k) {
        if (tp.first + dx[k] < 0 || tp.first + dx[k] >= n || tp.second + dy[k] < 0 || tp.second + dy[k] >= m) continue;
        if (visited[tp.first + dx[k]][tp.second + dy[k]]) continue;
        if (abs(grid[tp.first + dx[k]][tp.second + dy[k]] - grid[tp.first][tp.second]) > mid) continue;
        s.push({tp.first + dx[k], tp.second + dy[k]});
      }
    }
    int reachc{0};
    for (int i{0}; i < waypoints; ++i) {
      if (visited[waypoint[i].first][waypoint[i].second]) {
        ++reachc;
      }
    }
    if (reachc == waypoints) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  cout << ans << "\n";

  return 0;
}
