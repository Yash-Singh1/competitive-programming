#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct DSU {
	vi e, sz; int msz; int comps; void init(int N) { e = vi(N,-1); comps = N; msz = 1; sz = vi(N, 1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		--comps;
		if (e[x] > e[y]) swap(x,y);
		sz[x] += sz[y];
		sz[y] = sz[x];
		msz = max(sz[y], msz);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	DSU ds;
	ds.init(n);

	int x, y;
	for (int i{0}; i < m; ++i) {
		cin >> x >> y;
		--x; --y;
		ds.unite(x, y);
		cout << ds.comps << " " << ds.msz << "\n";
	}

	return 0;
}
