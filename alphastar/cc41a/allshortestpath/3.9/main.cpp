#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int x, y;

  vector<vector<int>> g(n, vector<int>(n));
  for (int i{0}; i < m; ++i) {
    cin >> x >> y; --x; --y;
    g[x][y] = 1;
    g[y][x] = 1;
  }

  for (int k{0}; k < n; ++k) {
    for (int i{0}; i < n; ++i) {
      if (g[i][k]) {
        for (int j{0}; j < n; ++j) {
          if (g[k][j]) {
            if (!g[i][j] || (g[i][j] > g[i][k] + g[k][j])) {
              g[i][j] = g[i][k] + g[k][j];
            }
          }
        }
      }
    }
  }

  vector<int> v(n);
  for (int i{0}; i < n; ++i) {
    if (!v[i]) {
      for (int j{0}; j < n; ++j) {
        if (g[i][j]) {
          cout << j+1 << ' ';
          v[j] = 1;
        }
      }
      cout << '\n';
    }
  }

  return 0;
}
