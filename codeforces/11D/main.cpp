#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define LSOne(S) (S & -S)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	int x, y;
	for (int i{0}; i < m; ++i) {
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	// {mask, end}
	// Since we are dropping the start we need to ensure that transitions only transition to more significant bits then the LSOne
	vector<vector<ll>> dp(1<<n, vector<ll>(n));
	vector<vector<ll>> d2(1<<n, vector<ll>(n));
	for (int i{0}; i < n; ++i) {
		dp[((1<<n)-1)^(1<<i)][i] = 1;
	}

	for (int i{(1<<n)-2}; i >= 0; --i) {
		for (int j{0}; j < n; ++j) {
			int b{i};
			for (auto &v: g[j]) {
				if (v > __builtin_ctz(~b) && (b&(1<<v))) {
					dp[(b|(1<<v))^(1<<v)][v] += dp[b][j];
				} else if (v == __builtin_ctz(~b)) {
					d2[b][v] += dp[b][j];
				}
			}
		}
	}

	ll tot = 0;
	for (int i{0}; i < (1<<n)-1; ++i) {
		// cout << "PICKED " << n-__builtin_popcount(i) << " " << i << " " << d2[i][__builtin_ctz(~i)] << "\n";
		// for (int j{0}; j < n; ++j) {
		// 	cout << d2[i][j] << " ";
		// }
		// cout << "\n";
		// for (int j{0}; j < n; ++j) {
		// 	cout << dp[i][j] << " ";
		// }
		// cout << "\n";
		if (n-__builtin_popcount(i) <= 2) continue;
		tot += d2[i][__builtin_ctz(~i)];
	}

	cout << tot/2 << '\n';

  return 0;
}
