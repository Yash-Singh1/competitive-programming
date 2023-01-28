#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  cin >> m >> n;

  ld ans{0};
  for (int i{0}; i < m; ++i) {
    ans += (i + 1) * (pow((ld)(i + 1) / m, n) - pow((ld)(i) / m, n));
  }

  cout << fixed << setprecision(12) << ans << "\n";

  return 0;
}
