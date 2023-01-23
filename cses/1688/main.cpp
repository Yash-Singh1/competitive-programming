#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

struct segtree {
  int size;
  vector<pll> tree;
  void init(int n) {
    size = 1;
    while (size <= n) size *= 2;
    tree.assign(2 * size, {INT_MAX, -1});
  }

  pll merge(pll a, pll b) {
    if (a.first < b.first) {
      return a;
    } else {
      return b;
    }
  }

  void set(int i, int v, int x, int lx, int rx, int seti) {
    if (rx - lx == 1) {
      tree[x] = {v, seti};
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m, seti);
    } else {
      set(i, v, 2 * x + 2, m, rx, seti);
    }
    tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
  }

  void set(int i, int v, int seti) {
    set(i, v, 0, 0, size, seti);
  }

  pll mn(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx) return {INT_MAX, -1};
    if (lx >= l && rx <= r) {
      return tree[x];
    }
    int m = (lx + rx) / 2;
    return merge(mn(l, r, 2 * x + 1, lx, m), mn(l, r, 2 * x + 2, m, rx));
  }

  pll mn(int l, int r) {
    return mn(l, r, 0, 0, size);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> g(n);
  int boss;
  for (int i{1}; i < n; ++i) {
    cin >> boss; --boss;
    g[boss].push_back(i);
  }

  vector<int> cval, back(n);
  stack<pair<int,int>> s;
  vector<int> depth(n);
  depth[0] = 0;
  s.push({0, -1});
  while (s.size()) {
    int u = s.top().first;
    int p = s.top().second;
    s.pop();
    if (p >= 0) {
      depth[u] = depth[p] + 1;
      back[p] = cval.size();
      cval.push_back(p);
    }
    if (g[u].size() == 0) {
      back[u] = cval.size();
      cval.push_back(u);
    }
    for (auto &v: g[u]) {
      if (v != p) {
        s.push({v, u});
      }
    }
  }

  segtree st;
  st.init((int)cval.size());
  for (int i{0}; i < (int)cval.size(); ++i) {
    st.set(i, depth[cval[i]], cval[i]);
  }

  int a, b;
  while (q--) {
    cin >> a >> b;
    --a; --b;
    cout << st.mn(min(back[a], back[b]), max(back[a], back[b]) + 1).second+1 << "\n";
  }

  return 0;
}
