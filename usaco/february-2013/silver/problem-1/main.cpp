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

	freopen("tractor.in", "r", stdin);
	freopen("tractor.out", "w", stdout);

	int n;
	cin >> n;

	vector<vector<int>> grid(n, vector<int>(n));

	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < n; ++j) {
			cin >> grid[i][j];
		}
	}

	vector<pair<int,pair<pair<int,int>,pair<int,int>>>> edges(4*n*n);
	vector<int> dx = {0, 0, 1, -1};
	vector<int> dy = {1, -1, 0, 0};
	int tot_connections{0};
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < n; ++j) {
			for (int k{0}; k < 4; ++k) {
				if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= n) continue;
				edges[tot_connections] = {abs(grid[i][j] - grid[i + dx[k]][j + dy[k]]), {{i, j}, {i + dx[k], j + dy[k]}}};
				++tot_connections;
			}
		}
	}

	DSU dsu;
	dsu.init(n * n);
	int sz{1};

	edges.resize(tot_connections);
	sort(edges.begin(), edges.end());
	int cost{0};
	for (auto &edge: edges) {
		dsu.unite(edge.second.first.first * n + edge.second.first.second, edge.second.second.first * n + edge.second.second.second);
		cost = max(cost, edge.first);
		sz = max(sz, dsu.size(edge.second.first.first * n + edge.second.first.second));
		if (sz >= (n * n + 1) / 2) {
			cout << cost << "\n";
			return 0;
		}
	}

	return 0;
}
