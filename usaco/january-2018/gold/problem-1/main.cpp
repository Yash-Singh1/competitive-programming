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

	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

	int n, q;
	cin >> n >> q;

	vector<pair<int,pair<int,int>>> edges(n - 1);
	for (int i{1}; i < n; ++i) {
		cin >> edges[i - 1].second.first >> edges[i - 1].second.second >> edges[i - 1].first;
	}

	sort(edges.begin(), edges.end(), greater<pair<int,pair<int,int>>>());

	vector<pair<pair<int,int>,int>> queries(q);
	for (int i{0}; i < q; ++i) {
		cin >> queries[i].first.first >> queries[i].first.second;
		queries[i].second = i;
	}
	sort(queries.begin(), queries.end(), greater<pair<pair<int,int>,int>>());

	vector<int> ans(q);
	// int relavance{INT_MAX};
	int j{0};
	DSU ds;
	ds.init(n);
	for (int i{0}; i < q; ++i) {
		int sz = ds.size(queries[i].first.second);
		for (; j < n - 1 && edges[j].first >= queries[i].first.first; ++j) {
			ds.unite(edges[j].second.first, edges[j].second.second);
			sz = ds.size(queries[i].first.second);
		}
		ans[queries[i].second] = sz - 1;
	}

	for (auto &ansee: ans) {
		cout << ansee << "\n";
	}

	return 0;
}
