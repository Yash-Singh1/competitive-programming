#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  ll ans{0};
  for (ll i{1}; i <= n; ++i) {
    assert(i > 0);
    ll amt{n/i};
    ll end{n/amt};
    assert(end >= i);
    ans += ((((end - i + 1) % MOD) * 500000004LL % MOD * ((i + end) % MOD) % MOD) % MOD * amt) % MOD;
    assert(ans >= 0);
    ans %= MOD;
    i = end;
  }

  cout << ans << "\n";

  return 0;
}
