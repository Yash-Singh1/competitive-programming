#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 1) {
    cout << 0 << "\n";
    return 0;
  }

  vector<int> g[n];
  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  int cur{0};
  for (int j{0}; j < 2; ++j) {
    stack<pair<pair<int,int>,int>> s;
    s.push({{cur, -1}, 0});
    int ans{0};
    int mxi{-1};
    while (!s.empty()) {
      pair<pii,int> stop{s.top()};
      s.pop();
      if (stop.second > ans) {
        ans = stop.second;
        mxi = stop.first.first;
      }
      for (auto &ne: g[stop.first.first]) {
        if (ne != stop.first.second) {
          s.push({{ne, stop.first.first}, stop.second + 1});
        }
      }
    }
    if (j == 1) {
      cout << ans << "\n";
    }
    cur = mxi;
  }

  return 0;
}
