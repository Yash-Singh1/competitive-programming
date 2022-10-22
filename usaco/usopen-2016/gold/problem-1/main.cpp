#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(pair<ll, ll> in[], ll n) {
  multiset<pair<ll, ll>> lx, ly, rx, ry;

  for (ll i{0}; i < n; ++i) {
    rx.insert({in[i].first, in[i].second});
    ry.insert({in[i].second, in[i].first});
  }

  ll tot = (rx.rbegin()->first - rx.begin()->first) * (ry.rbegin()->first - ry.begin()->first);
  ll ans = tot;

  while (rx.size() > 1) {
    auto low{rx.begin()};
    ll xaimlow = low->first;
    while (low->first == xaimlow) {
      rx.erase({xaimlow, low->second});
      ry.erase({low->second, xaimlow});
      lx.insert({xaimlow, low->second});
      ly.insert({low->second, xaimlow});
      if (!rx.empty()) low = rx.begin();
    }
    if (rx.empty()) {
      break;
    }
    ans = min(ans, ((rx.rbegin()->first - rx.begin()->first) * (ry.rbegin()->first - ry.begin()->first)) + ((lx.rbegin()->first - lx.begin()->first) * (ly.rbegin()->first - ly.begin()->first))); 
  }

  return tot - ans;
}

void rev(ll n, pair<ll, ll> in[]) {
  for (ll i{0}; i < n; ++i) {
    ll s{in[i].first};
    in[i].first = in[i].second;
    in[i].second = s;
  }
}

int main()
{
  ofstream fout("split.out");
  ifstream fin("split.in");

  ll n;
  fin >> n;

  pair<ll, ll> a[n];
  for (ll i{0}; i < n; ++i) {
    fin >> a[i].first >> a[i].second;
  }

  if (n == 3) {
    fout << 0;
    return 0;
  }

  ll ori = solve(a, n);
  rev(n, a);
  ori = max(ori, solve(a, n));
  fout << ori;
}
