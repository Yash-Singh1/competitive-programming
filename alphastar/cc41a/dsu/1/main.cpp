#include <bits/stdc++.h>

using namespace std;

// KACTL DSU Implementation

typedef vector<int> vi;

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

  int n, m;
  cin >> n >> m;

  DSU dsu;
  dsu.init(n);
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y; --x; --y;
    if (!dsu.unite(x, y)) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}
