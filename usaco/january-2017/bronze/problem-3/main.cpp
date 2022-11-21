#include <bits/stdc++.h>

using namespace std;

bool invalid(int n, vector<vector<int>> g) {
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (g[i][j] == 1) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cowtip.in", "r", stdin);
  freopen("cowtip.out", "w", stdout);

  int n;
  cin >> n;

  vector<vector<int>> g(n, vector<int>(n, 0));
  char x;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> x;
      g[i][j] = x - '0';
    }
  }

  int tot{0};
  int r{n-1};
  while (r >= 0) {
    while (r >= 0) {
      for (int i{0}; i < n; ++i) {
        if (g[i][r]) {
          goto endloop;
        }
      }
      --r;
      continue;
      endloop: break;
    }
    ++tot;
    for (int i{0}; i < n; ++i) {
      if (i != 0 && g[i][r] != g[i-1][r]) {
        ++tot;
      }
    }
    if (g[n-1][r] == 0) {
      --tot;
    }
    bool zero{1};
    for (int i{n-1}; i >= 0; --i) {
      if (zero && g[i][r] == 0) continue;
      zero = 0;
      if (g[i][r] == 1) {
        g[i][r] = 0;
        for (int j{r-1}; j >= 0; --j) {
          g[i][j] = 1 - g[i][j];
        }
      }
    }
  }

  cout << tot << "\n";

  return 0;
}
