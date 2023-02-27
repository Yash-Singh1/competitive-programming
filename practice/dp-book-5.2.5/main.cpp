// Unable to test, but this is my implementation of DP Book problem 5.2.5

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<vector<ll>>> dp(19, vector<vector<ll>>(1<<9, vector<ll>(2, -1)));
vector<int> di;
ll mx;

ll dfs(int pos, int b, int under) {
	if (pos >= di.size()) return (b == 0) ? 1 : 0;
	if (dp[pos][b][under] != -1) return dp[pos][b][under];
	int limit = 9;
	if (!under) {
		limit = di[pos];
	}
	ll sm{0};
	for (int i{0}; i <= limit; ++i) {
		sm += dfs(pos + 1, b - ((b & (1<<i)) ? (1<<i) : 0), under || (i < limit));
	}
	return (dp[pos][b][under] = sm);
}

void regenmx() {
	di.clear();
	while (mx) {
		di.push_back(mx%10);
		mx /= 10;
	}
	reverse(di.begin(), di.end());
}

void reset() {
	for (int i{0}; i < 19; ++i) {
		for (int j{0}; j < (1<<9); ++j) {
			for (int k{0}; k < 2; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
	cin >> n;

	reset();
	mx = n;
	regenmx();

	cout << dfs(0, (1<<9)-1, 0) << "\n";

  return 0;
}
