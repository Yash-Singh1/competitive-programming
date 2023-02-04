#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define LSOne(S) (S & -S)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
	cin >> n >> x;

	vector<ll> a(n);
	for (int i{0}; i < n; ++i) cin >> a[i];

	// we can use bitmask dp to find out all bitmasks that sum up what weights
	// we need to find what is the min # of bitmasks to find full match
	// for (int i{0}; i < (1<<n); ++i) {
	// 	int b{i};
	// 	ll sm{0};
	// 	while (b) {
	// 		sm += a[__builtin_ctz(LSOne(b))];
	// 		b -= LSOne(b);
	// 	}
	// 	dp[i][1] = sm;
	// }

  // {min groups, min left weight}
	vector<pll> dp(1<<n, {LLONG_MAX, LLONG_MAX});
	dp[(1<<n)-1] = {0, 0};
  for (int k{(1<<n)-1}; k >= 0; --k) {
    if (dp[k].first == LLONG_MAX) continue;
    int b{k};
    while (b) {
      if (a[__builtin_ctz(b)] + dp[k].second <= x) {
        if ((dp[k].first < dp[k - LSOne(b)].first) || (dp[k].first == dp[k - LSOne(b)].first && a[__builtin_ctz(b)] + dp[k].second < dp[k - LSOne(b)].second)) {
          dp[k - LSOne(b)] = {dp[k].first, a[__builtin_ctz(b)] + dp[k].second};
        }
      } else if ((dp[k].first+1 < dp[k - LSOne(b)].first) || (dp[k].first+1 == dp[k - LSOne(b)].first && min(a[__builtin_ctz(b)], dp[k].second) < dp[k - LSOne(b)].second)) {
        dp[k - LSOne(b)] = {dp[k].first + 1, min(a[__builtin_ctz(b)], dp[k].second)};
      }
      b -= LSOne(b);
    }
    // dp[k][j + 1] = min(dp[k][j + 1], 0LL);
  }

	cout << dp[0].first+1 << "\n";

  return 0;
}
