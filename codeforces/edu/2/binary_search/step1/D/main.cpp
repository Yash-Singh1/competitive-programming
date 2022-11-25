#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a+n);

  int k;
  cin >> k;

  int x, y;
  while (k--) {
    cin >> x >> y;
    cout << (upper_bound(a, a+n, y) - lower_bound(a, a+n, x)) << " ";
  }
  cout << "\n";

  return 0;
}
