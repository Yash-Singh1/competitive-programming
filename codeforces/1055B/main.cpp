#include <bits/stdc++.h>

using namespace std;

// KACTL DSU Implementation

typedef vector<int> vi;

typedef long long ll;

struct DSU {
	vi e; int sets; void init(int N) { e = vi(N,-1); sets = N; }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
    --sets;
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, l;
  cin >> n >> m >> l;

  vector<ll> hair(n);
  for (int i{0}; i < n; ++i) cin >> hair[i];

  DSU dsu;
  dsu.init(n);

  int g{0};
  for (int i{0}; i < n; ++i) {
    if (hair[i] > l) ++g;
    if (i != 0 && hair[i - 1] > l && hair[i] > l) {
      dsu.unite(i - 1, i);
    }
    if (i != n - 1 && hair[i + 1] > l && hair[i] > l) {
      dsu.unite(i, i + 1);
    }
  }

  int t, p, d;
  while (m--) {
    cin >> t;
    if (t == 0) {
      cout << dsu.sets - (n - g) << "\n";
    } else {
      cin >> p >> d;
      --p;
      if (hair[p] <= l && hair[p] + d > l) {
        ++g;
        if (p != 0 && hair[p - 1] > l) dsu.unite(p - 1, p);
        if (p != n - 1 && hair[p + 1] > l) dsu.unite(p + 1, p);
      }
      hair[p] += d;
    }
  }

  return 0;
}
