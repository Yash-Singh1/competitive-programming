#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
vector<ll> ldist, lcost(1000000+2);
vector<ll> rdist, rcost(1000000+2);
vector<ll> a;
ll calccost(ll k, pii both) {
  // cout << k << ' ' << lcost[k] << '\n';
  // return lcost[k]*both.first + rcost[k]*both.second;
  ll u = both.first;
  ll d = both.second;
  auto b4 = upper_bound(a.begin(), a.end(), k);
  if (b4 == a.begin()) {
    u = 0;
  } else b4 = prev(b4);
  auto after = lower_bound(a.begin(), a.end(), k);
  if (after == a.end()) d = 0;
  ll b4n = b4 - a.begin() + 1;
  ll aftern = a.size() - (after - a.begin());
  return (u*ldist[b4n-1] + u * b4n * (k - *b4) + aftern * (*after - k) * d + d * rdist[after - a.begin()]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  a.resize(n);
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  ll q;
  cin >> q;
  vector<pii> qs(q);
  for (ll i{0}; i < q; ++i) {
    cin >> qs[i].first >> qs[i].second;
  }

  ldist.resize(n);
  ldist[0] = 0;
  for (ll i{1}; i < n; ++i) {
    ldist[i] = ldist[i-1] + i*(a[i] - a[i-1]);
  }
  rdist.resize(n);
  rdist[n-1] = 0;
  for (ll i{n-2}; i >= 0; --i) {
    rdist[i] = rdist[i+1] + (n-i-1)*(a[i+1] - a[i]);
  }

  // lcost.resize(1000000+1);
  ll ap{0};
  lcost[0] = 0;
  for (ll i{0}; i <= 1000000; ++i) {
    lcost[i] = (i?lcost[i-1]:0) + ap;
    if (a[ap] == i) ++ap;
  }

  // rcost.resize(1000000+2);
  ap = n-1;
  rcost[1000000] = 0;
  for (ll i{1000000}; i >= 0; --i) {
    rcost[i] = rcost[i+1] + (n-ap-1);
    if (a[ap] == i) --ap;
  }

  for (auto qq: qs) {
    ll l{a[0]}, r{a[n-1]};
    for (ll i{0}; i < 30; ++i) {
      // ll delta = (r-l)/3;
      ll m1 = (l+r)/2;
      ll m2 = m1 + 1;
      (calccost(m1, qq) > calccost(m2, qq)) ? l = m1 : r = m2;
    }
    // cout << l << ' ' << r << '\n';
    cout << min(min(min(calccost(l, qq), calccost(l+1, qq)), min(calccost(l+2, qq), calccost(l+3, qq))), min(calccost(a[0], qq), calccost(a[n-1], qq))) << '\n';
  }

  return 0;
}
