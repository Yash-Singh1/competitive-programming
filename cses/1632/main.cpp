#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
  return a.second < b.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  pair<ll,ll> a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a,a+n,cmp);

  multiset<ll>s;
  for (ll i{0}; i < k; ++i) {
    s.insert(1);
  }

  ll tot{0};
  for (ll i{0}; i < n; ++i) {
    if (s.upper_bound(a[i].first) == s.begin()) {
      continue;
    }
    s.erase(prev(s.upper_bound(a[i].first)));
    s.insert(a[i].second);
    ++tot;
  }

  cout << tot << "\n";

  return 0;
}
