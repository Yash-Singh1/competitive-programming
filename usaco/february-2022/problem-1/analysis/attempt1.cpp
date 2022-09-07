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
    cin >> a[0];
    map<int, bool> m;
    m[0] = 1;
    m[a[0]] = 1;
    bool all{true};
    for (int i{1}; i < n; ++i) {
      cin >> a[i];
      if (a[i] != a[0]) {
        all = 0;
      }
      a[i] += a[i - 1];
      m[a[i]] = 1;
    }
    if (all) {
      cout << 0 << endl;
      continue;
    }
    bool g{false};
    for (int i{n - 2}; i >= 1; --i) {
      bool good{true};
      int dist{a[n - 1] - a[i]};
      if (dist == 0) {
        continue;
      }
      for (int j{dist}; j <= a[n - 1]; j += dist) {
        if (m.find(j) == m.end()) {
          good = false;
          break;
        }
      }
      if (good) {
        cout << dist << endl;
        g = true;
        break;
      }
    }
    if (!g) {
      cout << n - 1 << endl;
    }
  }
  return 0;
}
