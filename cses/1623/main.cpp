#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }

  ll ans{LLONG_MAX};

  ll pw{pow(2,n)};
  for (ll i{0}; i < pw; ++i) {
    ll j{i};
    ll sm1{0}, sm2{0};
    for (ll k{0}; k < n; ++k) {
      if (j & 1) {
        sm1 += a[k];
      } else {
        sm2 += a[k];
      }
      j >>= 1;
    }
    ans = min(ans,abs(sm1-sm2));
  }

  cout << ans << "\n";

  return 0;
}
