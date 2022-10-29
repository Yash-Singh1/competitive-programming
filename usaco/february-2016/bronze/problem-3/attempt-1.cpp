#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  ll n, b;
  cin >> n >> b;

  ll rlans{LLONG_MAX};
  ll rlanspos{-1};

  vector<ll> coordsx;
  vector<pair<ll,ll>> coordsy;
  for (ll i{0}; i < n; ++i) {
    ll x, y;
    cin >> x >> y;
    coordsx.push_back(x);
    coordsy.push_back({y,x});
  }
  sort(coordsx.begin(),coordsx.end());
  sort(coordsy.begin(),coordsy.end());

  for (ll i{0}; i <= b; i += 2) {
    ll query = (ll)distance(coordsx.begin(),lower_bound(coordsx.begin(),coordsx.end(),i));
    if (max(query,n-query) < rlans) {
      rlans = max(query,n-query);
      rlanspos = i;
    }
  }

  ll ans{LLONG_MAX};
  for (ll i{0}; i <= b; i += 2) {
    ll query = (ll)distance(coordsy.begin(),lower_bound(coordsy.begin(),coordsy.end(),pair<ll,ll>{i,LLONG_MIN}));

    ll l{0}, r{0};
    for (ll j{0}; j < query; ++j) {
      if (coordsy[j].second >= rlanspos) {
        ++r;
      } else {
        ++l;
      }
    }
    ll l2{0},r2{0};
    for (ll j{query}; j < n; ++j) {
      if (coordsy[j].second >= rlanspos) {
        ++r2;
      } else {
        ++l2;
      }
    }

    ans = min(max(max(l,r),max(l2,r2)),ans);
  }

  cout << ans << "\n";

  return 0;
}
