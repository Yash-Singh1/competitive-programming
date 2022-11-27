#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    if (n & 1) {
      for (int i{0}; i < n; ++i) {
        cout << "1 ";
      }
    } else {
      cout << "1 ";
      for (int i{0}; i < n-1; ++i) {
        cout << n+1 << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}
