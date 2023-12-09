#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t;
  cin >> n >> m >> t;

  vector<vector<int>> g(n, vector<int>(n));
  int x, y, z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z; --x; --y;
    g[x][y] = g[x][y] ? min(g[x][y], z) : z;
  }

  for (int k{0}; k < n; ++k) {
    for (int i{0}; i < n; ++i) {
      if (g[i][k]) {
        for (int j{0}; j < n; ++j) {
          if (i != j && g[k][j] && (max(g[i][k], g[k][j]) < g[i][j] || !g[i][j])) {
            g[i][j] = max(g[i][k], g[k][j]);
          }
        }
      }
    }
  }

  while (t--) {
    cin >> x >> y; --x; --y;
    if (x == y) {
      cout << 0 << '\n';
    } else if (g[x][y]) {
      cout << g[x][y] << '\n';
    } else {
      cout << -1 << '\n';
    }
  }

  return 0;
}
