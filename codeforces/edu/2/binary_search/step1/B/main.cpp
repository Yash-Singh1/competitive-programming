#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  int x;
  while (k--) {
    cin >> x;
    cout << (upper_bound(a, a+n, x) - a) << "\n";
  }

  return 0;
}
