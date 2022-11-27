#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  ll a[n];
  ll sm{0}, mn{LLONG_MAX};
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
    sm += a[i];
    mn = min(mn, a[i]);
  }

  ll l{1}, r{sm}, ans{-1};
  while (l <= r) {
    ll m{(l+r)/2}, sz{n - k + 1}, mxsz{LLONG_MIN}, smc{0}, szz{0}, divisions{0};
    for (ll i{0}; i < n; ++i) {
      if (smc + a[i] > m || szz == sz) {
        ++divisions;
        mxsz = max(mxsz, smc);
        smc = a[i];
        szz = 1;
        sz = (n - i) - (k - divisions) + 1;
      } else {
        smc += a[i];
        ++szz;
      }
    }
    ++divisions;
    mxsz = max(mxsz, smc);
    if (divisions <= k) {
      r = m - 1;
      ans = mxsz;
    } else {
      l = m + 1;
    }
  }

  cout << ans << "\n";

  return 0;
}
