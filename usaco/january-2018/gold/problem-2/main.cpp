#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> depth;
vector<int> dist;

void dfs(int u, int p) {
	for (auto &v: g[u]) {
		if (v != p) {
			dfs(v, u);
			depth[u] = min(depth[u], depth[v] + 1);
		}
	}
	if (depth[u] == INT_MAX) {
		depth[u] = 0;
	}
}

int ans = 0;

void dfs2(int u, int p) {
	if (dist[u] >= depth[u]) {
		++ans;
	} else {
		for (auto &v: g[u]) {
			if (v != p) dfs2(v, u);
		}
	}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("atlarge.in", "r", stdin);
  freopen("atlarge.out", "w", stdout);

  int n, k;
	cin >> n >> k;
	--k;

	g.resize(n);

	int x, y;
	for (int i{1}; i < n; ++i) {
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	if (g[k].size() == 1) {
		cout << 1 << '\n';
		return 0;
	}

	// to have subtree s covered, we must have a child of subtree s with depth higher than the distance to the root of s
	// otherwise, each of the children of s must supply their own farmers

	dist.resize(n);
	queue<pair<int,int>> q;
	q.push({k, -1});
	while (q.size()) {
		int u = q.front().first;
		int p = q.front().second;
		q.pop();
		for (auto &v: g[u]) {
			if (v != p) {
				q.push({v, u});
				dist[v] = dist[u] + 1;
			}
		}
	}

	depth.assign(n, INT_MAX);
	dfs(k, -1);
	dfs2(k, -1);

	cout << ans << '\n';

  return 0;
}
