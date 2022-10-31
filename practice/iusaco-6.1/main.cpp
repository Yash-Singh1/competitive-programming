#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int x[n], y[n];
  for (int i{0}; i < n; ++i) {
    cin >> x[i];
  }
  for (int i{0}; i < n; ++i) {
    cin >> y[i];
  }
  int ans{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      ans = max(ans, (int)pow(abs(x[j] - x[i]), 2) + (int)pow(abs(y[j] - y[i]), 2));
    }
  }

  cout << ans << "\n";

  return 0;
}
