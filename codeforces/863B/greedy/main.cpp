#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int a[2*n];
  for (int i{0}; i < 2*n; ++i) {
    cin >> a[i];
  }

  sort(a,a+2*n);
  int ans{INT_MAX};
  for (int i{0}; i < 2*n; ++i) {
    for (int j{0}; j < 2*n; ++j) {
      if (i == j) continue;
      int gp{0};
      for (int k{0}; k < 2*n; ++k) {
        if (k == i || k == j) {
          continue;
        }
        int diff{1};
        if (k+1 == i || k+1==j) {
          ++diff;
        }
        if (k+diff==i || k+diff == j) {
          ++diff;
        }
        gp += abs(a[k + diff] - a[k]);
        k += diff;
      }
      ans = min(gp, ans);
    }
  }

  cout << ans << "\n";

  return 0;
}
