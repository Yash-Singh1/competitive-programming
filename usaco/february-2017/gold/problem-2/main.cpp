#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("nocross.in", "r", stdin);
  freopen("nocross.out", "w", stdout);

  ll n;
  cin >> n;
  vector<ll> barns(2*n);
  for (ll i{0}; i < 2*n; i += 2) {
    cin >> barns[i];
  }
  for (ll i{1}; i < 2*n; i += 2) {
    cin >> barns[i];
  }

  ll ans{0};
  vector<vector<ll>> dp(n, vector<ll>(n));
  for (ll i{0}; i < 2*n; ++i) {
    ans = max(ans, dp[i]);
    if (i != 0) {
      dp[i] = max(dp[i], ans);
    }
    for (ll j{i + 1}; j < 2*n; j += 2) {
      if (abs(barns[i] - barns[j]) <= 4) {
        dp[j + 1] = max(dp[j + 1], dp[i] + 1);
      }
      
    }
  }

  for (ll i{0}; i <= 2*n; ++i) {
    cout << dp[i] << " ";
  }
  cout << "\n";

  cout << ans << "\n";

  return 0;
}
