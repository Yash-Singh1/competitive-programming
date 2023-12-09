#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int x, y;
  vector<set<int>> g(n);
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    g[x].insert(y);
    g[y].insert(x);
  }

  for (auto &v: g) {
    for (auto &u: v) {
      cout << u << ' ';
    }
    cout << '\n';
  }

  return 0;
}
