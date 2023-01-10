#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  DSU ds;
  ds.init(n);
  int c, x, y;
  while (q--) {
    cin >> c >> x >> y;
    if (c == 0) {
      ds.unite(x, y);
    } else {
      cout << ds.sameSet(x, y) << "\n";
    }
  }

  return 0;
}
