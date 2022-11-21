#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("fenceplan.in", "r", stdin);
  freopen("fenceplan.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  pair<int,int> pos[n];
  for (int i{0}; i < n; ++i) {
    cin >> pos[i].first >> pos[i].second;
  }

  vector<int> g[n];
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  bool visited[n];
  for (int i{0}; i < n; ++i) {
    visited[i] = 0;
  }

  int ans{INT_MAX};
  for (int i{0}; i < n; ++i) {
    if (visited[i]) continue;
    stack<int> s;
    s.push(i);
    pair<pair<int,int>,pair<int,int>> dims{pos[i], pos[i]};
    while (!s.empty()) {
      int stop{s.top()};
      s.pop();
      visited[stop]=1;
      dims.first.first = min(pos[stop].first, dims.first.first);
      dims.first.second = min(pos[stop].second, dims.first.second);
      dims.second.first = max(pos[stop].first, dims.second.first);
      dims.second.second = max(pos[stop].second, dims.second.second);
      for (auto &ne: g[stop]) {
        if (!visited[ne]) {
          s.push(ne);
        }
      }
    }
    ans = min(ans, 2 * (dims.second.second - dims.first.second) + 2 * (dims.second.first - dims.first.first));
  }

  cout << ans << "\n";

  return 0;
}
