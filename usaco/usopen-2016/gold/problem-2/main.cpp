#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct DSU {
	vi e; vector<bool> a; int numSets; void init(int N) { e = vi(N,-1); a = vector<bool>(N, 0); numSets = 0; }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	int add(int x) {
		// cout << "add " << x << "\n";
		a[x] = 1; return e[x] < 0 ? ++numSets : numSets;
	}
	bool unite(int x, int y) { // union by size
		bool included{a[x] && a[y]};
		if (!included) return 0;
		// cout << "preunite " << x << " " << y << "\n";
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		if (included) {
			// cout << "unite " << x << " " << y << "\n";
			--numSets;
		}
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;

	vector<int> g[n];
	int x, y;
	for (int i{0}; i < m; ++i) {
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vector<int> removal(n);
	for (int i{0}; i < n; ++i) {
		cin >> removal[n - i - 1];
		--removal[n - i - 1];
	}

	DSU ds;
	ds.init(n);
	vector<bool> ans(n);
	int ansi{n};
	for (auto &rm: removal) {
		ds.add(rm);
		// cout << ds.numSets << " ";
		for (auto &ne: g[rm]) {
			ds.unite(rm, ne);
		}
		ans[ansi - 1] = ds.numSets <= 1;
		--ansi;
		// cout << ds.numSets << "\n";
	}

	for (auto anspart: ans) {
		if (anspart) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
