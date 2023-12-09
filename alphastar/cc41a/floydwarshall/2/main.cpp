#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, f, m;
  cin >> n >> f >> m;

  vector<int> fav(f);
  for (int i{0}; i < f; ++i) {
    cin >> fav[i];
    --fav[i];
  }

  vector<vector<int>> g(n, vector<int>(n));
  int x, y, z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    g[x][y] = z;
    g[y][x] = z;
  }

  for (int k{0}; k < n; ++k) {
    for (int i{0}; i < n; ++i) {
      if (g[i][k]) {
        for (int j{0}; j < n; ++j) {
          if (g[k][j] && i != j) {
            if (!g[i][j] || g[i][k] + g[k][j] < g[i][j]) {
              g[i][j] = g[i][k] + g[k][j];
            }
          }
        }
      }
    }
  }

  double mn{INT_MAX};
  int mni{-1};
  for (int i{0}; i < n; ++i) {
    int sm{0};
    for (int j{0}; j < n; ++j) {
      if (find(fav.begin(), fav.end(), j) != fav.end()) {
        sm += g[i][j];
      }
    }
    double avg = (double)sm / f;
    if (avg < mn) {
      mni = i;
      mn = avg;
    }
  }

  cout << mni+1 << '\n';

  return 0;
}
