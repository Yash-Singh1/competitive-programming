#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("taming.in", "r", stdin);
  freopen("taming.out", "w", stdout);

  int n;
  cin >> n;

  bool appeared[n];
  for (int i{1}; i < n; ++i) {
    appeared[i] = 0;
  }
  appeared[0] = 1;
  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }
  for (int i{0}; i < n; ++i) {
    if (a[i] > i) {
      cout << -1 << "\n";
      return 0;
    } else if (a[i] != -1) {
      for (int j{i}; j > i - a[i]; --j) {
        if (j < 0) {
          cout << -1 << "\n";
          return 0;
        }
        if (appeared[j] || a[j] > (j - (i - a[i]))) {
          cout << -1 << "\n";
          return 0;
        }
      }
      appeared[i - a[i]] = 1;
    }
  }
  int mn{0};
  for (int i{0}; i < n; ++i) {
    if (appeared[i]) {
      ++mn;
    }
  }
  cout << mn << " ";

  bool didntbreak[n];
  for (int i{0}; i < n; ++i) {
    didntbreak[i] = 0;
  }
  for (int i{0}; i < n; ++i) {
    if (a[i] == -1) continue;
    // mark all ranges where breaking in would be disturbing counter
    for (int j{i}; j > i - a[i] && j >= 0; --j) {
      didntbreak[j] = 1;
    }
  }

  int mx{0};
  for (int i{0}; i < n; ++i) {
    if (!didntbreak[i]) {
      ++mx;
    }
  }
  cout << mx << "\n";

  return 0;
}
