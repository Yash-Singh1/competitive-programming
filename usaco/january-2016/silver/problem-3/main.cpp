#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int dx[4] {0, 0, 1, -1};
int dy[4] {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("gates.in", "r", stdin);
  freopen("gates.out", "w", stdout);

  int n;
  cin >> n;

  vector<vector<bool>> visited(4005, vector<bool>(4005, 0));
  for (int i{0}; i < 4005; ++i) {
    for (int j{0}; j < 4005; ++j) {
      if (i <= 2 || j <= 2 || i >= 4003 || j >= 4003) {
        visited[i][j] = 1;
      }
    }
  }
  pair<int,int> pos{2002, 2002};
  char x;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    if (x == 'N') {
      pos.first -= 2;
      visited[pos.first + 1][pos.second] = 1;
    } else if (x == 'S') {
      pos.first += 2;
      visited[pos.first - 1][pos.second] = 1;
    } else if (x == 'W') {
      pos.second -= 2;
      visited[pos.first][pos.second + 1] = 1;
    } else {
      pos.second += 2;
      visited[pos.first][pos.second - 1] = 1;
    }
  }

  int tots{-1};
  for (int i{3}; i < 4003; i += 2) {
    for (int j{3}; j < 4003; j += 2) {
      if (visited[i][j]) continue;
      stack<pii> s;
      s.push({i, j});
      while (!s.empty()) {
        pii stop{s.top()};
        s.pop();
        if (visited[stop.first][stop.second]) continue;
        visited[stop.first][stop.second] = 1;
        for (int k{0}; k < 4; ++k) {
          // if (stop.first + dx[k]*2 < 0 || stop.first + dx[k]*2 > 4000 || stop.second + dy[k]*2 < 0 || stop.second + dy[k]*2 > 4000) {
          //   continue;
          // }
          if (visited[stop.first + dx[k]*2][stop.second + dy[k]*2] || visited[stop.first + dx[k]][stop.second + dy[k]]) continue;
          s.push({stop.first + dx[k]*2, stop.second + dy[k]*2});
        }
      }
      ++tots;
    }
  }

  cout << tots << "\n";

  return 0;
}
