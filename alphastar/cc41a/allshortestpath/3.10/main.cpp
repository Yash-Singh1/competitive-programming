#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, b;
  cin >> n >> m >> a >> b; --a; --b;
  int x, y, z;

  vector<vector<int>> g(n, vector<int>(n));
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z; --x; --y;
    g[x][y] = z;
    g[y][x] = z;
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

  cout << g[a][b] << '\n';

  return 0;
}
