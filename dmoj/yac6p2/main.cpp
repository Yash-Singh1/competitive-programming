// Passes sample, doesn't pass rest

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int a[n], b[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }
  for (int i{0}; i < n; ++i) {
    cin >> b[i];
  }

  bool val{1};
  int tot{0};
  for (int i{0}; i < n; ++i) {
    if (a[i] != b[i]) {
      if (b[i] == -1 || a[i] == -1 || a[b[i] - 1] == i + 1) {
        val = 0;
        break;
      }
      ++tot;
    }
  }

  if (val) {
    cout << tot << "\n";
    for (int i{0}; i < n; ++i) {
      if (a[i] != b[i]) {
        cout << i + 1 << " " << b[i] << "\n";
      }
    }
  } else {
    cout << -1 << "\n";
  }

  return 0;
}
