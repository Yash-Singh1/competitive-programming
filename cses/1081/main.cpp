#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n;

  vector<int> m(1000001);
  // fill(m.begin(), m.end(), 0);

  for (int i{0}; i < n; ++i) {
    cin >> x;
    for (int j{1}; j * j <= x; ++j) {
      if (x % j == 0) {
        ++m[j];
        if (j * j == x) continue;
        ++m[x / j];
      }
    }
  }

  int ans;
  for (int i{1000000}; i >= 1; --i) {
    if (m[i] >= 2) {
      ans = i;
      break;
    }
  }
  cout << ans << "\n";

  return 0;
}
