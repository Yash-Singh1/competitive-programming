#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> g[n];
  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  stack<pair<int,int>> s;
  s.push({0, -1});
  int ans{0}, goal, c;
  // for (auto &e: g[2]) cout << e << " ";
  // cout << "\n\n";
  while (!s.empty()) {
    pair<int,int> stop{s.top()};
    s.pop();
    if (g[stop.first].size() <= 1) continue;
    goal = g[stop.first].size() + (stop.second == -1 ? 1 : 0);
    c = 1;
    while (c < goal) {
      ++ans;
      c <<= 1;
    }
    // cout << stop.first << "-\n";
    // cout << ans << "\n";
    ans += g[stop.first].size() - (stop.second == -1 ? 0 : 1);
    // cout << ans << "\n";
    for (auto &ne: g[stop.first]) {
      if (ne != stop.second) {
        s.push({ne, stop.first});
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
