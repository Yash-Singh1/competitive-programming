#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> ns;
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    if (x == y) continue;
    if (x == k) ns.push_back(y);
    else if (y == k) ns.push_back(x);
  }

  sort(ns.begin(), ns.end());
  cout << ns.size() << '\n';
  for (auto &ne: ns) {
    cout << ne << '\n';
  }

  return 0;
}
