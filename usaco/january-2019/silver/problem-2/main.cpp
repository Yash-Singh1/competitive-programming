#include <bits/stdc++.h>

using namespace std;

int dx[4] {1, -1, 0, 0};
int dy[4] {0, 0, 1, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);

  int n;
  cin >> n;

  char a[n][n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  bool visited[n][n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      visited[i][j] = 0;
    }
  }
  int marea{0}, mperim{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (a[i][j] == '.' || visited[i][j]) continue;
      queue<pair<int,int>> q;
      q.push({i,j});
      int area{0};
      int perim{0};
      while (!q.empty()) {
        pair<int,int> qtop = q.front();
        q.pop();
        if (visited[qtop.first][qtop.second]) continue;
        visited[qtop.first][qtop.second] = 1;
        ++area;
        int score{0};
        for (int k{0}; k < 4; ++k) {
          if (qtop.first + dx[k] < 0 || qtop.first + dx[k] >= n || qtop.second + dy[k] < 0 || qtop.second + dy[k] >= n || a[qtop.first + dx[k]][qtop.second + dy[k]] == '.') continue;
          ++score;
          if (visited[qtop.first + dx[k]][qtop.second + dy[k]]) continue;
          q.push({qtop.first + dx[k], qtop.second + dy[k]});
        }
        perim += 4 - score;
      }
      if (area > marea) {
        marea = area;
        mperim = perim;
      } else if (area == marea) {
        mperim = min(perim, mperim);
      }
    }
  }

  cout << marea << " " << mperim << "\n";

  return 0;
}
