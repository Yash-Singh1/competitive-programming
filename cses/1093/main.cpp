#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  ll target{n*(n+1)/2};
  if (target & 1) {
    cout << 0 << "\n";
    return 0;
  }
  target /= 2;

  vector<vector<ll>> dp(n + 1, vector<ll>(target*2+1, 0));
  dp[0][0] = 1;

  ll ans{0};
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < target; ++j) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;
      dp[i + 1][j + i + 1] += dp[i][j];
      dp[i + 1][j + i + 1] %= MOD;
    }
    ans += (dp[i][target] % MOD);
    ans %= MOD;
  }

  cout << ans << "\n";

  return 0;
}
