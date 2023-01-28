#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(12);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  ld ans = ((ld)a / b) / (1 - (((ld)(b - a) / b) * ((ld)(d - c) / d)));
  cout << ans << "\n";

  return 0;
}
