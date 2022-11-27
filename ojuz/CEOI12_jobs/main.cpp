#include <bits/stdc++.h>

using namespace std;

typedef int ll;

ll n, d, m;

bool sort2(pair<ll,ll>a,pair<ll,ll>b) {
  return a.second < b.second;
}

bool val(ll machines, pair<ll,ll> a[]) {
  map<ll,ll> ma;
  ma.insert({0, machines});
  pair<ll,ll> val;
  for (ll i{0}; i < m; ++i) {
    auto search = ma.upper_bound(a[i].first+d);
    val = *prev(search);
    if (search == ma.begin()) {
      return 0;
    } else {
      prev(search)->second = val.second - 1;
      if (val.second == 1) {
        ma.erase(prev(search));
      }
      ++ma[max(val.first, a[i].first)+1];
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> d >> m;
  pair<ll,ll> a[m];
  for (ll i{0}; i < m; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a,a+m);

  ll l{1}, r{m}, ans{-1};
  while (l <= r) {
    ll m{(l+r)/2};
    if (val(m, a)) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }

  cout << ans << "\n";

  set<pair<ll,ll>> s;
  for (ll i{0}; i < m; ++i) {
    s.insert(a[i]);
  }
  for (ll i{0}; i < n; ++i) {
    ll mecuse{0};
    while (!s.empty() && mecuse < ans && s.begin()->first <= i + 1) {
      cout << s.begin()->second+1 << " ";
      s.erase(s.begin());
      ++mecuse;
    }
    cout << "0\n";
  }

  return 0;
}
