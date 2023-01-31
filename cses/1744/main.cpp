#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b;
  cin >> a >> b;

  vector<vector<ll>> dp(a + 1, vector<ll>(b + 1, INT_MAX));
  for (ll i{1}; i <= min(a, b); ++i) {
    dp[i][i] = 0;
  }

  for (ll i{1}; i <= a; ++i) {
    for (ll j{1}; j <= b; ++j) {
      dp[i][j] = min(dp[i][j], min(j - 1 + j * (i - 1), i - 1 + i * (j - 1)));
      for (ll k{1}; k < i; ++k) {
        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
      }
      for (ll k{1}; k < j; ++k) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
      }
    }
  }

  cout << dp[a][b] << "\n";

  return 0;
}
