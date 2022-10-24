#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cmp(pair<ll,ll>a,pair<ll,ll>b) {
  return (a.first-a.second)<(b.first-b.second);
}

bool cmp_input(pair<ll,ll>a,pair<ll,ll>b) {
  return a.second>b.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("mountains.in", "r", stdin);
  freopen("mountains.out", "w", stdout);

  ll n;
  cin >> n;

  set<pair<ll,ll>, decltype(cmp)*> s(cmp);

  pair<ll,ll> a[n];
  for (int i=0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a,a+n,cmp_input);

  ll seen{0};
  for (ll i=0; i < n; ++i) {
    auto query = s.upper_bound(a[i]);
    if (s.size() == 0 || query == s.begin() || (--query)->first + query->second < a[i].first + a[i].second) {
      ++seen;
      s.insert(a[i]);
    }
  }

  cout << seen;

  return 0;
}
