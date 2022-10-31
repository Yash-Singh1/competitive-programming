#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);

  int n;
  cin >> n;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  int mn{INT_MAX};
  for (int i{0}; i< n; ++i) {
    int sm{0};
    for (int j{0}; j < n; ++j) {
      if (j > i) {
        sm += a[j] * (j - i);
      } else if (j < i) {
        sm += a[j] * (n - (i - j));
      }
    }
    mn = min(mn, sm);
  }

  cout << mn << "\n";

  return 0;
}
