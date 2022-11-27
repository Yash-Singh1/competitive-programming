#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;

  int x;
  while (t--) {
    cin >> n;
    for (int i{0}; i < n; ++i) cin >> x;
    cout << 1 << " " << n << "\n";
  }

  return 0;
}
