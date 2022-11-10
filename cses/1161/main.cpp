#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// strat: go to median and divide recursively at that point

ll find_s_median(ll a[], ll l, ll r) {
  if (r-l == 0) {
    return 0;
  }
  long double mid{(long double)(a[r]-(l==0?0:a[l-1]))};
  ll cost{(ll)mid};
  mid/=2;
  ll dist{LLONG_MAX}, mans{0};
  long double newdist;
  for (ll i{l}; i <= r; ++i) {
    newdist = (long double)(a[i] - (l==0?0:a[l-1])) - mid;
    // cout << i << " " << newdist << " " << mid << "\n";
    if (newdist > 0 && dist != LLONG_MAX) break;
    if (abs(newdist) < dist) {
      dist = abs(newdist);
      mans = i;
    }
  }
  // if (mans == 0) {
  //   cout << l << " " << r << " " << cost << " " << mid << " " << a[l] << " " << a[r] << "\n";
  //   cout << "WAT\n";
  // }
  // cout << l << " " << r << " " << cost << " " << mans << " " << mid << " " << dist << "\n";
  cost += find_s_median(a, l, mans);
  // cout << l << " " << r << " " << cost << "\n";
  cost += find_s_median(a, mans+1, r);
  // cout << l << " " << r << " " << cost << "\n";
  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x;
  cin >> x >> n;

  ll a[n];
  for (ll i{0}; i < n;++i) {
    cin >> a[i];
  }
  sort(a,a+n, greater<ll>());

  for (ll i{1}; i < n; ++i) {
    a[i] += a[i - 1];
  }

  // for (ll i{0}; i < n; ++i) {
  //   cout << a[i] << " ";
  // }
  // cout << "\n";

  cout << find_s_median(a, 0, n-1) << "\n";

  return 0;
}
