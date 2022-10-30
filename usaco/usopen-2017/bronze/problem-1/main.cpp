#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);

  int x, y;
  cin >> x >> y;

  int dist{1};
  int tot{0};
  int loc{x};
  while (true) {
    for (;loc != x + dist; loc += (dist < 0 ? -1 : 1)) {
      ++tot;
      if (loc == y) {
        cout << tot-1 << "\n";
        return 0;
      }
    }
    dist *= -2;
  }

  cout << tot << "\n";

  return 0;
}
