#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  int m, s;
  while (t--) {
    cin >> m >> s;
    int mx{0};
    int a[m];
    for (int i{0}; i < m; ++i) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    sort(a,a+m);
    int sreq{0};
    for (int j{1}; j < mx; ++j) {
      if (find(a, a+m, j) == a+m) {
        sreq += j;
      }
    }
    s -= sreq;
    if (s < 0) {
      cout << "NO\n";
      continue;
    } else if (s == 0) {
      cout << "YES\n";
      continue;
    }
    int k{mx+1};
    while (s > 0) {
      s -= k;
      ++k;
    }
    if (s == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
