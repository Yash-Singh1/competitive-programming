#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  int a[n][n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      char x;
      cin >> x;
      if (x == '.') {
        a[i][j] = 0;
      } else {
        a[i][j] = 1;
      }
    }
  }

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (i != 0) {
        a[i][j] += a[i - 1][j];
      }
      if (j != 0) {
        a[i][j] += a[i][j - 1];
      }
      if (i != 0 && j!= 0) {
        a[i][j] -= a[i - 1][j - 1];
      }
    }
  }

  while (q--) {
    int y1, x1, y2, x2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1;
    --y1;
    --x2;
    --y2;
    int ans{a[x2][y2]};
    if (y1 != 0) {
      ans -= a[x2][y1 - 1];
    }
    if (x1 != 0) {
      ans -= a[x1 - 1][y2];
    }
    if (y1 != 0 && x1 != 0) {
      ans += a[x1 - 1][y1 - 1];
    }
    cout << ans << endl;
  }

  return 0;
}
