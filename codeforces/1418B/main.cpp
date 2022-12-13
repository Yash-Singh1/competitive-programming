#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    int a[n];
    bool locked[n];
    for (int i{0}; i < n; ++i) {
      cin >> a[i];
    }
    int unlocky{0};
    for (int i{0}; i < n; ++i) {
      cin >> locked[i];
      if (!locked[i]) ++unlocky;
    }
    int b[unlocky];
    int j{0};
    for (int i{0}; i < n; ++i) {
      if (!locked[i]) {
        b[j] = a[i];
        ++j;
      }
    }
    sort(b, b + unlocky, greater<int>());
    j = 0;
    for (int i{0}; i < n; ++i) {
      if (locked[i]) {
        cout << a[i] << " ";
      } else {
        cout << b[j] << " ";
        ++j;
      }
    }
    cout << "\n";
  }

  return 0;
}
