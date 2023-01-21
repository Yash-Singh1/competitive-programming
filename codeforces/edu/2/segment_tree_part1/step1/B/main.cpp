#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct segtree {
  int size;
  vector<ll> tree;
  void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(2 * size, 0LL);
  }

  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
  }

  void set(int i, int v) {
    set(i, v, 0, 0, size);
  }

  ll mn(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx) return INT_MAX;
    if (lx >= l && rx <= r) {
      return tree[x];
    }
    int m = (lx + rx) / 2;
    return min(mn(l, r, 2 * x + 1, lx, m), mn(l, r, 2 * x + 2, m, rx));
  }

  ll mn(int l, int r) {
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
      cout << st.mn(x, y) << "\n";
    }
  }

  return 0;
}
