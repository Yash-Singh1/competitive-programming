#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("teleport.in", "r", stdin);
  freopen("teleport.out", "w", stdout);

  int a, b, x, y;
  cin >> a >> b >> x >> y;

  cout << min(abs(b - a), min(abs(x - a) + abs(b - y), abs(y - a) + abs(b - x)));

  return 0;
}
