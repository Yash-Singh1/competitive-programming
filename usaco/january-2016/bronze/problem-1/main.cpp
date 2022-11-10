#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);

  int b1, b2, s1, s2, g1, g2, p1, p2;
  cin >> b1 >> b2 >> s1 >> s2 >> g1 >> g2 >> p1 >> p2;

  cout << ((p2 - p1) + (g2 - g1) + (s2 - s1)) << "\n" << ((p2 - p1) + (g2 - g1)) << "\n" << (p2 - p1) << "\n";

  return 0;
}
