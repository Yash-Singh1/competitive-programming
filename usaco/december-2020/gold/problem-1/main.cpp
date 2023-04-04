#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d;
  cin >> n >> d;

  queue<pair<int,int>> q;
  vector<vector<int>> outdist(n, vector<int>(n, -1));
  vector<vector<char>> grid(n, vector<char>(n));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == '#') {
        q.push({i, j});
        outdist[i][j] = 0;
      }
    }
  }

  int dx[4] {0, 1, 0, -1};
  int dy[4] {1, 0, -1, 0};
  while (q.size()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (outdist[x][y] > 0) continue;
    bool allsider{1};
    int mn{INT_MAX};
    for (int i{0}; i < 4; ++i) {
      if (x + dx[i] < 0 || x + dx[i] >= n) continue;
      if (y + dy[i] < 0 || y + dy[i] >= n) continue;
      if (grid[x + dx[i]][y + dy[i]] == '#') {
        allsider = 0;
        continue;
      }
      if (outdist[x + dx[i]][y + dy[i]] == -1) {
        q.push({x + dx[i], y + dy[i]});
      } else {
        mn = min(mn, outdist[x + dx[i]][y + dy[i]]);
      }
    }
    if (allsider) {
      outdist[x][y] = mn + 1;
    } else {
      outdist[x][y] = 0;
    }
  }

  // we do a BFS from the start points
  // if the minimum distance is less than or equal to d x outdist[x][y]
  vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (grid[i][j] == 'S') {
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  vector<vector<bool>> visited(n, vector<bool>(n));
  while (q.size()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    visited[x][y] = 1;
    for (int i{0}; i < 4; ++i) {
      if (dist[x + dx[i]][y + dy[i]] == INT_MAX && grid[x + dx[i]][y + dy[i]] != '#') {
        if (outdist[x][y] >= dist[x][y]/d) {
          dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
          q.push({x + dx[i], y + dy[i]});
        }
      }
    }
  }

  queue<pair<int,pair<int,int>>> qd;
  vector<vector<int>> mxleft(n, vector<int>(n, -1));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (visited[i][j]) {
        mxleft[i][j] = outdist[i][j];
        qd.push({outdist[i][j], {i, j}});
      }
    }
  }
  while (qd.size()) {
    int x = qd.front().second.first;
    int y = qd.front().second.second;
    int d = qd.front().first;
    qd.pop();
    if (d != mxleft[x][y]) continue;
    visited[x][y] = 1;
    if (!mxleft[x][y]) continue;
    for (int i{0}; i < 4; ++i) {
      if (grid[x + dx[i]][y + dy[i]] == '#') continue;
      if (mxleft[x][y] - 1 > mxleft[x + dx[i]][y + dy[i]]) {
        mxleft[x + dx[i]][y + dy[i]] = mxleft[x][y] - 1;
        qd.push({mxleft[x][y] - 1, {x + dx[i], y + dy[i]}});
      }
    }
  }

  int tot{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (visited[i][j]) {
        // cout << 1 << ' ';
        ++tot;
      } else {
        // cout << 0 << ' ';
      }
    }
    // cout << '\n';
  }

  cout << tot << '\n';

  return 0;
}
