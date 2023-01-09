#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;

    vector<int> a(n);
    for (int i{0}; i < n; ++i) {
      cin >> a[i];
    }
    int sm{0};
    bool f{0};
    for (int i{0}; i < n; ++i) {
      if (a[i] == sm) {
        f = 1;
      }
      sm += a[i];
    }

    if (f) {
      reverse(a.begin(), a.end());
      if (a[0] == a[1]) {
        f = 1; 
        for (int i{0}; i < n; ++i) {
          if (a[i] != a[0]) {
            int s{a[0]};
            a[0] = a[i];
            a[i] = s;
            f = 0;
            break;
          }
        }
      } else {
        f = 0;
      }
    }

    if (f) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto &el: a) {
        cout << el << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}
