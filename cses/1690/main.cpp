#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> tg(n);
  ll x, y;
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    tg[y].push_back(x);
  }

  vector<vector<ll>> dp(1<<n, vector<ll>(n));
  dp[1][0] = 1;

  for (ll mask{2}; mask < (1<<n); ++mask) {
    if ((mask&1)==0 || (mask&(1<<(n-1)) && mask != (1<<n)-1))continue;
    for (ll i{0}; i < n; ++i) {
      if ((mask & (1<<i)) == 0) continue;
      for (ll &v: tg[i]) {
        if (mask & (1<<v)) {
          dp[mask][i] += dp[mask - (1<<i)][v];
          dp[mask][i] %= MOD;
        }
      }
    }
  }

  cout << dp[(1<<n)-1][n-1] << "\n";

  return 0;
}
