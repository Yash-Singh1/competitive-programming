#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  
  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  for (int i{1}; i < n; ++i) {
    a[i] ^= a[i-1];
  }

  int x, y;
  while (q--) {
    cin >> x >> y;
    cout << (a[y-1] ^ (x>1?a[x-2]:0)) << "\n";
  }

  return 0;
}
