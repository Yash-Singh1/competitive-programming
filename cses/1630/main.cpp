// go1 is from like 6mo ago so ima do again

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cmp(pair<ll,ll>a, pair<ll,ll>b) {
  return a.first < b.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;cin >> n;

  pair<ll,ll>a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a,a+n,cmp);

  ll t{0};
  ll v{0};
  for (ll i{0}; i < n; ++i) {
    t += a[i].first;
    v += a[i].second - t;
  }

  cout << v << "\n";

  return 0;
}
