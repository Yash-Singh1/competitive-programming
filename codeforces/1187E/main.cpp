#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> g;
vector<ll> dp1, dp2;
vector<ll> p1, p2;
vector<ll> sz;

// Calculate sz and dp1
void dfs1(int u, int p) {
	sz[u] = 1;
	for (int &v: g[u]) {
		if (v == p) {
			continue;
		}
		dfs1(v, u);
		sz[u] += sz[v];
		dp1[u] += dp1[v];
	}
	dp1[u] += sz[u];
}

// Calculate cost incorporated for initial value of dp2
void dfs2(int u, int p) {
	if (p != -1) {
		p1[u] = p1[p] + sz[p] - sz[u];
		p2[u] = p2[p] + p1[u] + sz[p] - sz[u];
	}
	for (int &v: g[u]) {
		if (v == p) {
			continue;
		}
		dfs2(v, u);
	}
}

// Calculate dp2
void dfs3(int u, int p) {
	dp2[u] = (g[u].size() == 1 ? p2[u]+1 : 0);
	ll tot = 0;
	for (int &v: g[u]) {
		if (v == p) {
			continue;
		}
		tot += dp1[v];
	}
	for (int &v: g[u]) {
		if (v == p) {
			continue;
		}
		dfs3(v, u);
		if (dp2[v] + tot - dp1[v] > dp2[u]) {
			dp2[u] = dp2[v] + tot - dp1[v];
		}
	}
}

int main() {
	int n;
	cin >> n;

	g.resize(n); dp1.resize(n); dp2.resize(n); sz.resize(n);
	p1.resize(n); p2.resize(n);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[--x].push_back(--y);
		g[y].push_back(x);
	}

	// Run first DFS to calculate sz and dp1
	dfs1(0, -1);

	// Run second DFS to calculate p1 and p2
	dfs2(0, -1);

	// Run third DFS to calculate dp2
	dfs3(0, -1);

	// Find maximum dp1/dp2 among all nodes
	ll ans{0};
	for (int i = 0; i < n; ++i) {
		ans = max(ans, max(dp1[i], dp2[i]));
	}

	cout << ans << endl;
}
