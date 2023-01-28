/*
ID: saiansh1
LANG: C++
TASK: subset
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("subset.in", "r", stdin);
  freopen("subset.out", "w", stdout);

  ll n;
  cin >> n;

  if ((n * (n + 1)) % 4 != 0) {
    cout << 0 << "\n";
    return 0;
  }

  vector<vector<ll>> dp(n+1, vector<ll>(n*(n+1)/4+1));
  dp[0][0] = 1;
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j <= n*(n+1)/4; ++j) {
      dp[i + 1][j] += dp[i][j];
      if (j + i + 1 <= n*(n+1)/4) {
        dp[i + 1][j + i + 1] += dp[i][j];
      }
    }
  }
  cout << dp[n][n*(n+1)/4]/2 << "\n";
}
