#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  ll ans{1};
  for (ll i{1}; i <= n; ++i) {
    ans = (((ans * i) % MOD) + (i & 1 ? -1 : 1)) % MOD;
  }

  cout << ans << "\n";

  return 0;
}
