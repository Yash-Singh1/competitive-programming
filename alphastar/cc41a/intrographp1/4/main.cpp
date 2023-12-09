#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int x, y;

  vector<vector<int>> g(n);
  for (int i{0}; i < m; ++i) {
    cin >> x >> y; --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<bool> v(n);
  vector<pair<int,int>> comp(n);
  int j{0};
  for (int i{0}; i < n; ++i) {
    if (v[i]) continue;
    stack<int> s;
    s.push(i);
    while (s.size()) {
      int tp{s.top()};
      s.pop();
      v[tp] = 1;
      comp[tp] = {j, tp};
      for (auto &ne: g[tp]) {
        if (!v[ne]) s.push(ne);
      }
    }
    ++j;
  }

  sort(comp.begin(), comp.end());
  int cvert{0};
  cout << j << '\n';
  for (auto &vert: comp) {
    if (vert.first != cvert) {
      cvert = vert.first;
      cout << '\n';
    }
    cout << vert.second+1 << ' ';
  }
  cout << '\n';

  return 0;
}
