#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a[10];
  for (int i{0}; i < 10; ++i) {
    cin >> a[i];
  }

  int mx{0};
  for (int i{0}; i < (1<<10)-1; ++i) {
    int val{0};
    for (int j{0}; j < 10; ++j) {
      if (i&(1<<j)) {
        val ^= a[j];
      }
    }
    mx = max(val, mx);
  }

  cout << mx << "\n";

  return 0;
}
