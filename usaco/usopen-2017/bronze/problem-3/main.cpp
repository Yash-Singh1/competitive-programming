#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("art.in", "r", stdin);
  freopen("art.out", "w", stdout);

  int n;
  cin >> n;

  pair<pair<int,int>,pair<int,int>> rect[9];
  for (int i{0}; i < 9; ++i) {
    rect[i] = {{INT_MAX, INT_MAX}, {INT_MIN, INT_MIN}};
  }
  int grid[n][n];
  char nx;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> nx;
      if (nx == '0') continue;
      rect[nx - '1'].first.first = min(rect[nx - '1'].first.first, i);
      rect[nx - '1'].first.second = min(rect[nx - '1'].first.second, j);
      rect[nx - '1'].second.first = max(rect[nx - '1'].second.first, i);
      rect[nx - '1'].second.second = max(rect[nx - '1'].second.second, j);
      grid[i][j] = nx - '0';
    }
  }

  // for (int i{0}; i < 9; ++i) {
  //   cout << rect[i].first.first << " " << rect[i].first.second << " " << rect[i].second.first << " " << rect[i].second.second << "\n";
  // }

  bool ans[9];
  for (int i{0}; i < 9; ++i) {
    ans[i] = 1;
  }
  for (int k{0}; k < 9; ++k) {
    if (rect[k].first.first != INT_MAX) {
      for (int i{rect[k].first.first}; i <= rect[k].second.first; ++i) {
        for (int j{rect[k].first.second}; j <= rect[k].second.second; ++j) {
          if (grid[i][j] != k+1) {
            ans[grid[i][j]-1] = 0;
          }
        }
      }
    } else {
      ans[k] = 0;
    }
  }

  int pos{0};
  for (int i{0}; i < 9; ++i) {
    if (ans[i]) {
      ++pos;
    }
  }

  cout << pos << "\n";

  return 0;
}
