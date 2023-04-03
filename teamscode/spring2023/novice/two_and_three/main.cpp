// Didn't grundy because couldn't expand to 1e9
// Should have found some pattern

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000000

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<bool> dp(MAXN);
	dp[0]=1;
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;

	int mx0;
	for (int i{4}; i < MAXN; ++i) {
		dp[i] = !(dp[i/2]) || !(dp[i/3]);
		if (!dp[i]) {
			i = ((i-1)*2)+1;
			mx0 = ((i-1)*2)+1;
			// cout << ((i-1)*2+1 - i) + 1 << '\n';
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin  >> n;
		if (n == 1) {
			int a;
			cin >> a;
			cout << ((a >= MAXN ? "Miku" : (dp[a] ? "Nino" : "Miku"))) << '\n';
		}
	}

	// for (int i{0}; i < 100; ++i) {
	// 	cout << i << ' ' << dp[i] << '\n';
	// }

  return 0;
}
