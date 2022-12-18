#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    char a[n];
    for (int i{0}; i < n; ++i) {
      cin >> a[i];
    }
    int v{a[0] == '1' ? 1 : 0};
    for (int i{1}; i < n; ++i) {
      if (v != 0) {
        if (v > 0) {
          cout << '-';
          v -= a[i] == '1' ? 1 : 0;
        } else {
          cout << '+';
          v += a[i] == '1' ? 1 : 0;
        }
      } else {
        cout << '+';
        v += a[i] == '1' ? 1 : 0;
      }
    }
    cout << "\n";
  }

  return 0;
}
