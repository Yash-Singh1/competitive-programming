#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("balls.in", "r", stdin);
  // freopen("balls.out", "w", stdout);

  // 300 numbers, n*(n+1)*(n+2)/6
  vector<ll> pyramids(300);
  for (ll i{0}; i < 300; ++i) {
    pyramids[i] = (i + 1) * (i + 2) * (i + 3) / 6;
  }

  vector<ll> dp(1000000, LLONG_MAX);
  dp[0] = 0;
  for (ll i{0}; i < 300000; ++i) {
    assert(dp[i] != LLONG_MAX);
    for (auto &pyramid: pyramids) {
      dp[i + pyramid] = min(dp[i + pyramid], dp[i] + 1);
    }
  }

  ll t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    cout << dp[n] << "\n";
  }

  return 0;
}
