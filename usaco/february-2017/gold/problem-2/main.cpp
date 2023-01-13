#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);

	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (int i{0}; i < n; ++i) cin >> a[i];
	for (int i{0}; i < n; ++i) cin >> b[i];

	vector<vector<int>> dp(n + 1, vector<int> (n + 1));
	for (int i{0}; i <= n; ++i) {
		for (int j{0}; j <= n; ++j) {
			if (i != 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j != 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (i < n && j < n && abs(a[i] - b[j]) <= 4) {
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
			}
		}
	}

	cout << dp[n][n] << "\n";

	return 0;
}
