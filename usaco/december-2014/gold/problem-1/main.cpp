#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define LSOne(S) (S & -S)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("guard.in", "r", stdin);
  freopen("guard.out", "w", stdout);

  // Bitmask DP with the state being dp[mask] = {safety factor, {weight, height}}
	// Each additional cow will give c_strength - weight more safety and c_weight more weight
	// I guess storing the state as pairs should work because the bounds are 1e9 for the weight, height, and strength
	// We also need to check the height so it should be a tuple, need to figure out priority though (e.g. don't want high safety factor but too low height)
	// - or maybe we don't need to worry about that because these are permutations so mask weight is constant

  ll n, h;
  cin >> n >> h;

  vector<ll> height(n), weight(n), strength(n);
  for (int i{0}; i < n; ++i) {
    cin >> height[i] >> weight[i] >> strength[i];
  }

  vector<ll> hb(1<<n), wb(1<<n);
  for (int i{1<<n}; i >= 0; --i) {
    int b{i};
    while (b) {
      hb[i ^ LSOne(b)] = hb[i] + height[__builtin_ctz(b)];
      wb[i ^ LSOne(b)] = wb[i] + weight[__builtin_ctz(b)];
      b -= LSOne(b);
    }
  }

  vector<ll> dp(1<<n, -1);
  dp[(1<<n)-1] = LLONG_MAX;
  for (int i{(1<<n)-1}; i >= 0; --i) {
    int b{i};
    while (b) {
      if (strength[__builtin_ctz(b)] >= wb[i]) {
        dp[i ^ LSOne(b)] = max(dp[i ^ LSOne(b)], min(dp[i], (strength[__builtin_ctz(b)] - wb[i])));
      }
      b -= LSOne(b);
    }
  }

  ll ans{-1};
  for (int i{0}; i < (1<<n); ++i) {
    if (hb[i] >= h && dp[i] != -1) {
      ans = max(ans, dp[i]);
    }
  }

  if (ans == -1) {
    cout << "Mark is too tall\n";
  } else {
    cout << ans << "\n";
  }

  return 0;
}
