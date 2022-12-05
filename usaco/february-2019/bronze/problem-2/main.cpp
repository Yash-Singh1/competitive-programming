#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<int> g[n];
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x;--y; 
    g[x].push_back(y);
    g[y].push_back(x);
  }

  bool pos[n][4];
  for (int i{0}; i < n; ++i) {
    pos[i][0] = 1;
    pos[i][1] = 1;
    pos[i][2] = 1;
    pos[i][3] = 1;
  }

  int col[n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < 4; ++j) {
      if (pos[i][j]) {
        col[i] = j+1;
        break;
      }
    }
    for (auto &ne: g[i]) {
      pos[ne][col[i] - 1] = 0;
    }
  }

  for (int i{0}; i < n; ++i) cout << col[i];
  cout << "\n";

  return 0;
}
