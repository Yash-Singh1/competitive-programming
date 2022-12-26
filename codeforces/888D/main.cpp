#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

ll montmort[6] {1, 0, 1, 2, 9, 44};
ll factk[5] {1, 1, 2, 6, 24};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  ll ans{1};
  for (ll i{1}; i <= k; ++i) {
    ll f{1};
    for (ll j{n}; j > 0 && j > n - i; --j) {
      f *= j;
    }
    f /= factk[i];
    f *= montmort[i];
    // cout << f << " ";
    ans += f;
  }
  // cout << "\n";
  cout << ans << "\n";

  return 0;
}
