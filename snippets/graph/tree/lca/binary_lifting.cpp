#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & -S)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> st(n, vector<int>(20, -1));
  vector<vector<int>> g(n);
  for (int i{1}; i < n; ++i) {
    cin >> st[i][1];
    --st[i][1];
    g[st[i][1]].push_back(i);
  }

  for (int i{2}; i < 20; ++i) {
    for (int j{0}; j < n; ++j) {
      if (st[j][i - 1] != -1) {
        st[j][i] = st[st[j][i - 1]][i - 1];
      }
    }
  }

  stack<pair<int,int>> s;
  s.push({0, -1});
  vector<int> depth(n);
  while (s.size()) {
    int u = s.top().first;
    int p = s.top().second;
    s.pop();
    if (p > -1) depth[u] = depth[p] + 1;
    for (auto &v: g[u]) {
      if (v != p) {
        s.push({v, u});
      }
    }
  }

  int x, y;
  while (q--) {
    cin >> x >> y;
    --x; --y;
    int l{0}, r{min(depth[x], depth[y])}, ans{-1};
    while (l <= r) {
      int mid{(l+r)/2};
      int cur{x};
      int dx = depth[x] - mid, dy = depth[y] - mid;
      while (dx && cur != -1) {
        cur = st[cur][__builtin_ctz(dx)+1];
        dx -= LSOne(dx);
      }
      int cur2{y};
      while (dy && cur2 != -1) {
        cur2 = st[cur2][__builtin_ctz(dy)+1];
        dy -= LSOne(dy);
      }
      if (cur == cur2) {
        l = mid+1;
        ans = cur;
      } else {
        r = mid-1;
      }
    }
    cout << ans+1 << "\n";
  }

  return 0;
}
