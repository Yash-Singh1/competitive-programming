#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    if (n % 2 == 0) {
      cout << "YES\n";
      for (int i{0}; i < n; ++i) {
        if (i & 1) {
          cout << -1 << " ";
        } else {
          cout << 1 << " ";
        }
      }
      cout << "\n";
    } else if (n >= 5) {
      cout << "YES\n";
      for (int i{0}; i < n; ++i) {
        if (i & 1) {
          cout << -(n/2) << " ";
        } else {
          cout << (n/2)-1 << " ";
        }
      }
      cout << "\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
