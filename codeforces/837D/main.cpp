// Some weird integer overflow runtime error, idk wats happening
// Anyways logic works just ans messes up when computing big nums

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll p5(ll nu) {
  ll ans{0LL};
  while (nu % 5LL == 0LL) {
    ++ans;
    nu /= 5LL;
  }
  return ans;
}

ll counttrail(ll num) {
  int ans{0};
  while (!(num & 1)) {
    num >>= 1;
    ++ans;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(k + 1, vector<ll>(30, -1)));

  ll ans{0};
  dp[0][0][0] = 0;
  ll cur{0};
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < k; ++j) {
      for (ll l{0}; l < 30; ++l) {
        if (dp[cur][j][l] != -1) {
          dp[1 - cur][j + 1][l + p5(a[i])] = max(dp[1 - cur][j + 1][l + p5(a[i])], dp[cur][j][l] + counttrail(a[i]));
          dp[1 - cur][j][l] = max(dp[1 - cur][j][l], dp[cur][j][l]);
        }
        ans = max(ans, min(l, dp[1 - cur][k][l]));
      }
    }
    cur = 1 - cur;
  }
  cout << ans << "\n";

  return 0;
}
