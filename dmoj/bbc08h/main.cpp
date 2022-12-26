// 2*factorial(2*n-1)/(factorial(n)*factorial(n-1))-1

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

ll factorial(ll n) {
  if (n <= 1) return 1;
  return n * factorial(n - 1) % MOD;
}

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

  int n;
  cin >> n;
  ++n;

  cout << (2*factorial(2*n-1)%MOD*binpow(factorial(n)*factorial(n-1)%MOD, MOD - 2, MOD)%MOD-1+MOD)%MOD << "\n";

  return 0;
}
