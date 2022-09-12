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
    int sm{0};
    for (int i{0}; i < n; ++i) {
      cin >> a[i];
      sm += a[i];
    }
    for (int i{n}; i >= 0; --i) {
      if (sm % i == 0) {
        int cur = 0;
        int tar = sm / i;
        bool g{1};
        for (int j{0}; j < n; ++j) {
          cur += a[j];
          if (cur > tar) {
            g = 0;
            break;
          }
          if (cur == tar) {
            cur = 0;
          }
        }
        if (g) {
          cout << n - i << endl;
          break;
        }
      }
    }
  }

  return 0;
}
