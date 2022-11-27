#include <bits/stdc++.h>

using namespace std;

int movev[4] {1, -1, 0, 0};
int moveh[4] {0, 0, 1, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  char a[n][m];
  bool visited[n][m];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> a[i][j];
      visited[i][j] = 0;
    }
  }

  int rooms{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      if (visited[i][j] || a[i][j] == '#') {
        continue;
      }
      stack<pair<int,int>> s;
      s.push({i,j});
      while (!s.empty()) {
        pair<int,int> stop{s.top()};
        s.pop();
        visited[stop.first][stop.second] = 1;
        for (int k{0}; k < 4; ++k) {
          if ((stop.first + movev[k] < 0 || stop.first + movev[k] >= n) || (stop.second + moveh[k] < 0 || stop.second + moveh[k] >= m)) {
            continue;
          }
          if (visited[stop.first + movev[k]][stop.second + moveh[k]] || a[stop.first + movev[k]][stop.second + moveh[k]] == '#') continue;
          s.push({stop.first + movev[k], stop.second + moveh[k]});
        }
      }
      ++rooms;
    }
  }

  cout << rooms << "\n";

  return 0;
}
