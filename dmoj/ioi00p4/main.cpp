#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n, l;
	cin >> m >> n >> l;

	// calc min dist between each region in O(m^3*logm)
	// for each region, calc min dist between min region of each town
	// O(m^2*l)

	vector<int> cities(l);
	for (int i{0}; i < l; ++i) {
		cin >> cities[i]; --cities[i];
	}

	vector<vector<int>> region(m);
	vector<vector<int>> antir(n);
	vector<vector<int>> g(m, vector<int>(m));
	for (int i{0}; i < m; ++i) {
		int I;
		cin >> I;
		region[i].resize(I);
		for (int j{0}; j < I; ++j) {
			cin >> region[i][j]; --region[i][j];
			antir[region[i][j]].push_back(i);
		}
	}

	for (int i{0}; i < n; ++i) {
		for (auto &r: antir[i]) {
			for (auto &r2: antir[i]) {
				g[r][r2] = 1;
				g[r2][r] = 1;
			}
		}
	}

	vector<vector<int>> dist(m, vector<int>(m, INT_MAX));
	queue<int> q;
	for (int i{0}; i < m; ++i) {
		q.push(i);
		dist[i][i] = 0;
		while (q.size()) {
			int u = q.front();
			q.pop();
			for (int v{0}; v < m; ++v) {
				if (g[u][v] && dist[i][u] + 1 < dist[i][v]) {
					dist[i][v] = dist[i][u] + 1;
					q.push(v);
				}
			}
		}
	}

	int ans{INT_MAX};
	int ansi{-1};
	for (int i{0}; i < m; ++i) {
		int sol{0};
		for (int j{0}; j < l; ++j) {
			int msol{INT_MAX};
			for (auto &r: antir[cities[j]]) {
				msol = min(msol, dist[r][i]);
			}
			sol += msol;
		}
		if (sol < ans) {
			ansi = i+1;
			ans = sol;
		}
	}

	cout << ans << '\n' << ansi << '\n';

  return 0;
}
