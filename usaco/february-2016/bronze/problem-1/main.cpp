#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x, y, m;
  cin >> x >> y >> m;

  int ans{0};
  for (int i{0}; i <= m / y; ++i) {
    ans = max(ans, (m - (i * y)) / x * x + (i * y));
  }

  cout << ans << "\n";

  return 0;
}
