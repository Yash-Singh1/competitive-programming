#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

ll binpow(ll a, ll b, ll m) {
  if (b == 0) {
    return 1;
  } else if (a == 0) {
    return 0;
  }
  ll curp{a};
  ll pow{0};
  ll ans{1};
  while (b) {
    if (b & (1<<pow)) {
      b &= b - 1;
      ans *= curp;
      ans %= m;
    }
    ++pow;
    curp *= curp;
    curp %= m;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("help.in", "r", stdin);
  freopen("help.out", "w", stdout);

  ll n;
  cin >> n;

  ll ans{0}, c{0};
  vector<pair<ll,ll>> r(2*n);
  for (ll i{0}; i < n; ++i) {
    cin >> r[i<<1].first >> r[(i<<1)|1].first;
    r[i<<1].second = 1;
    r[(i<<1)|1].second = -1;
  }
  sort(r.begin(), r.end());

  for (ll i{0}; i < (n<<1); ++i) {
    c += r[i].second;
    if (r[i].second == 1) {
      ans += binpow(2, n - c, MOD);
      ans %= MOD;
    }
  }
  // ans *= binpow(2, c, MOD);
  // ans %= MOD;

  cout << ans << "\n";

  return 0;
}
