#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i {0}; i < n; ++i) {
    cin >> a[i];
  }

  for (int b{0}; b < 1<<n; ++b) {
    for (int i{0}; i < n; ++i) {
      if ((b&(1<<i))) cout << a[i] << ' ';
    }
    if (b) cout << '\n';
  }

  return 0;
}
