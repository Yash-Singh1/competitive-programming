#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> g[5000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("mootube.in", "r", stdin);
  freopen("mootube.out", "w", stdout);

  int n, q;
  cin >> n >> q;

  int x, y, z;
  for (int i{1}; i< n; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    g[x].push_back({y,z});
    g[y].push_back({x,z});
  }

  int k, t;
  for (int i{0}; i < q; ++i) {
    cin >> k >> t;
    --t;
    stack<pair<pair<int,int>,int>> s;
    s.push({{t,-1},INT_MAX});
    int ans{0};
    while (!s.empty()) {
      pair<pair<int,int>,int> stop{s.top()};
      s.pop();
      if (stop.second >= k) {
        ++ans;
      }
      for (auto &ne: g[stop.first.first]) {
        if (ne.first != stop.first.second) {
          s.push({{ne.first, stop.first.first}, min(ne.second, stop.second)});
        }
      }
    }
    cout << ans-1 << "\n";
  }

  return 0;
}
