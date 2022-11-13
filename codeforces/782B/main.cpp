#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

bool validate(pair<ll,ll> a[], ll n, ld dist) {
  ld lrange{-1000000000}, rrange{1000000000};
  for (ll i{0}; i < n; ++i) {
    lrange = max(lrange, a[i].first - (dist * a[i].second));
    rrange = min(rrange, a[i].first + (dist * a[i].second));
    if (rrange < lrange) {
      return false;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  pair<ll,ll> a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i].first;
  }
  for (int i{0}; i < n; ++i) {
    cin >> a[i].second;
  }
  sort(a,a+n);

  ld l{0}, r{10000000000}, ans{-1};
  while ((r-l) > (ld)1e-6) {
    ld mid{(r+l)/2};
    if (validate(a, n, mid)) {
      r = mid;
      ans = mid;
    } else {
      l = mid;
    }
  }

  cout << fixed << setprecision(9) << ans << "\n";

  return 0;
}
