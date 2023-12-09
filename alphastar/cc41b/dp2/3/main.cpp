#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  ll sm{(n * (n+1)) / 2};
  if (sm&1) {
    cout << "0\n";
    return 0;
  }
  sm >>= 1;

  vector<vector<ll>> dp(n+1, vector<ll>(sm+1));
  dp[0][0] = 1;
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j <= sm; ++j) {
      dp[i+1][j] += dp[i][j];
      if (j + i + 1 <= sm) {
        dp[i+1][j+i+1] += dp[i][j];
      }
    }
  }

  cout << dp[n][sm]/2 << '\n';

  return 0;
}
