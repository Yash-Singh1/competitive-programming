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

ll fact(ll n) {
  if (n <= 1) {
    return 1;
  }
  return fact(n - 1) * n % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  cout << ((fact(n + k - 1) * binpow(fact(n - 1), MOD - 2, MOD) % MOD) * binpow(fact(k), MOD - 2, MOD)) % MOD << "\n";

  return 0;
}
