#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i{0}; i < n; ++i) {
      cin >> a[i];
    }
    sort(a,a+n);
    int ans[n];
    if (n % 2 != 0) {
      ans[0] = a[n/2];
    }
    int k{n};
    for (int i{0}; i < n/2; ++i) {
      ans[--k] = a[i];
      ans[--k] = a[n-i-1];
    }
    for (int i{0}; i < n; ++i) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}
