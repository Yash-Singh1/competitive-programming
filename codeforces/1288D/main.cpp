#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int a[n][m];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  int l{1}, r{1000000000};
  pair<int,int> ansi;
  while (l <= r) {
    int mid{(l+r)/2};
    unordered_set<int> validator;
    unordered_map<int,int> valid;
    for (int i{0}; i < n; ++i) {
      int mask{0};
      for (int j{0}; j < m; ++j) {
        mask <<= 1;
        if (a[i][j] >= mid) {
          mask |= 1;
        }
      }
      validator.insert(mask);
      valid[mask] = i;
    }
    pair<int,int> found{-1,-1};
    for (auto &e: validator) {
      for (auto &e2: validator) {
        if ((e | e2) == (1<<m)-1) {
          found = {valid[e], valid[e2]};
        }
      }
    }
    if (found.first == -1) {
      r = mid - 1;
    } else {
      ansi = found;
      l = mid + 1;
    }
  }

  cout << ansi.first + 1 << " " << ansi.second + 1 << "\n";

  return 0;
}
