#include <bits/stdc++.h>

using namespace std;

int x, y, k, m;
int done[101][101];
int mn{INT_MAX};

void explore(int a, int b, int tot) {
  mn = min(mn, abs(m - (a+b)));
  if (tot == k) return;
  if (done[a][b] <= tot) {
    return;
  }
  done[a][b] = tot;
  explore(0, b, tot+1);
  explore(a, 0, tot+1);
  explore(x, b, tot+1);
  explore(a, y, tot+1);
  explore(a + min(x - a, b), b - min(b, x - a), tot+1);
  explore(a - min(a, y - b), b + min(y - b, a), tot+1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  cin >> x >> y >> k >> m;
  for (int i{0}; i <= x; ++i) {
    for (int j{0}; j <= y; ++j) {
      done[i][j] = INT_MAX;
    }
  }

  explore(0, 0, 0);
  cout << mn << "\n";

  return 0;
}
