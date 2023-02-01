#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;

  vector<ll> dp1(1000000), dp2(1000000);
  dp1[0] = 1; dp2[0] = 1;
  for (ll i{1}; i <= 1000000; ++i) {
    dp1[i] = ((dp1[i - 1] * 2LL % MOD) + dp2[i - 1]) % MOD;
    dp2[i] = ((dp2[i - 1] * 4LL % MOD) + dp1[i - 1]) % MOD;
  }

  ll n;
  while (t--) {
    cin >> n;
    cout << (dp1[n-1] + dp2[n-1]) % MOD << "\n";
  }

  return 0;
}
