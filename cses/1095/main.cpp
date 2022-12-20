#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  
  ll a, b;
  while (n--) {
    cin >> a >> b;
    if (b == 0) {
      cout << 1 << "\n";
      continue;
    } else if (a == 0) {
      cout << 0 << "\n";
      continue;
    }
    ll ans{1};
    ll pow{0};
    ll curp{a};
    while (b) {
      if (b & (1<<pow)) {
        ans *= curp;
        ans %= MOD;
        b &= b-1;
      }
      ++pow;
      curp *= curp;
      curp %= MOD;
    }
    cout << ans << "\n";
  }

  return 0;
}
