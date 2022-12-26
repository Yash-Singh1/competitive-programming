// WA, but too much to work on ima give up on this one, I still get the sol, maybe need to group common numbers

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;
const ll MAXN = 200005;
vector<ll> fact(MAXN);
vector<ll> inv(MAXN);

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

  fact[0] = 1;
  for (ll i{1}; i < MAXN; ++i) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }

  inv[MAXN-1] = binpow(fact[MAXN - 1], MOD - 2, MOD);
  for (ll i{MAXN-1}; i > 0; --i) {
    inv[i - 1] = inv[i] * i % MOD;
  }

  ll t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (ll i{0}; i < n; ++i) {
      cin >> a[i];
    }
    if (m == 1) {
      cout << n << "\n";
      continue;
    }
    sort(a.begin(),a.end());
    ll l{0}, r{0}, ans{0};
    while (l < n) {
      while (r < n && a[r] - a[l] <= k) {
        ++r;
      }
      if (r - l >= m) {
        ans += (fact[r - l] * inv[m] % MOD * inv[r - l - m] % MOD) - (r - l > m ? (fact[r - l - 1] * inv[m] % MOD * inv[r - l - 1 - m] % MOD) : 0);
        ans %= MOD;
      }
      ++l;
    }
    cout << ans << "\n";
  }

  return 0;
}
