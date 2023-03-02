#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & -S)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  vector<vector<int>> t(200001, vector<int>(30, INT_MAX));
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    t[i][0] = a[i];
  }

  for (int j{1}; j < 30; ++j) {
    for (int i{0}; i < n; ++i) {
      if (t[i][j - 1] == INT_MAX || i + (1<<(j-1)) >= n) continue;
      t[i][j] = min(t[i][j - 1], t[i + (1<<(j-1))][j - 1]);
    }
  }

  int l, r;
  while (q--) {
    cin >> l >> r;
    --l; --r;
    int lg{__builtin_clz(1) - __builtin_clz(r-l+1)};
    cout << min(t[l][lg], t[r - (1<<lg) + 1][lg]) << '\n';
  }

  return 0;
}
