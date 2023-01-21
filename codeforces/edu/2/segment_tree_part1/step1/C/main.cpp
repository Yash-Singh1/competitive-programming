#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

struct segtree {
  int size;
  vector<pll> tree;
  void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    tree.resize(2 * size);
  }

  pll combine(pll a, pll b) {
    if (a.first < b.first) return a;
    if (b.first < a.first) return b;
    return {a.first, a.second + b.second};
  }

  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = {v, 1};
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
  }

  void set(int i, int v) {
    set(i, v, 0, 0, size);
  }

  pll mn(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx) return {INT_MAX, 0};
    if (lx >= l && rx <= r) {
      return tree[x];
    }
    int m = (lx + rx) / 2;
    return combine(mn(l, r, 2 * x + 1, lx, m), mn(l, r, 2 * x + 2, m, rx));
  }

  pll mn(int l, int r) {
    return mn(l, r, 0, 0, size);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  segtree st;
  st.init(n);
  int x;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    st.set(i, x);
  }
  int y, t;
  while (m--) {
    cin >> t >> x >> y;
    if (t == 1) {
      st.set(x, y);
    } else {
      pll ans = st.mn(x, y);
      cout << ans.first << " " << ans.second << "\n";
    }
  }

  return 0;
}
