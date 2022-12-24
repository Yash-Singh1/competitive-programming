#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

vector<ll> fact(1000001);
vector<ll> inv(1000001);

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
  for (ll i{1}; i <= 1000000; ++i) {
    fact[i] = fact[i - 1LL] * i;
    fact[i] %= MOD;
  }

  inv[1000000] = binpow(fact[1000000], MOD - 2, MOD);
  for (ll i{1000000-1}; i >= 0; --i) {
    inv[i] = inv[i+1] * (i + 1) % MOD;
  }

  ll n, a, b;
  cin >> n;

  while (n--) {
    cin >> a >> b;
    cout << ((fact[a] * inv[b] % MOD) * inv[a - b]) % MOD << "\n";
  }

  return 0;
}
