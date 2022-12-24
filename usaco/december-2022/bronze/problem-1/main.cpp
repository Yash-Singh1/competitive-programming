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
  sort(a, a + n);

  ll mx{LLONG_MIN}, mxi{-1};
  for (ll i{0}; i <= 1000000; ++i) {
    ll tot{a + n - lower_bound(a, a+n, i)};
    if (tot * i > mx) {
      mx = tot * i;
      mxi = i;
    }
  }

  cout << mx << " " << mxi << "\n";

  return 0;
}
