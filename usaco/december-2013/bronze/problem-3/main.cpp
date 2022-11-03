#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll after[12];
pair<ll,ll> p[12];

ll pairingsStuck(ll tot, ll pairs, map<ll,ll> a, set<ll> aval) {
  if (aval.empty()) {
    set<ll> s;
    bool gotstuck{0};
    for (ll i{0}; i < n; ++i) {
      ll pos{a[i]};
      s.clear();
      s.insert(pos);
      while (pos != -1) {
        pos = after[pos];
        if (pos != -1) {
          pos = a[pos];
        }
        if (s.find(pos) != s.end()) {
          gotstuck = 1;
          break;
        }
        s.insert(pos);
      }
      if (gotstuck) break;
    }
    if (gotstuck) {
      return 1;
    }
    return 0;
  }
  ll k{*aval.begin()};
  a[k] = -1;
  aval.erase(aval.begin());

  ll sm{0};
  for (ll i{0}; i < n; ++i) {
    if (aval.find(i) != aval.end()) {
      aval.erase(i);
      a[k] = i;
      a[i] = k;
      sm += pairingsStuck(tot+1, pairs, a, aval);
      a.erase(i);
      aval.insert(i);
    }
  }

  return sm;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);

  cin >> n;

  for (ll i{0}; i < n; ++i) {
    cin >> p[i].second >> p[i].first;
  }
  sort(p,p+n);
  for (ll i{0}; i < n; ++i) {
    ll match{-1};
    for (ll j{0}; j < n; ++j) {
      if (p[j].first == p[i].first && p[j].second > p[i].second) {
        match = j;
        break;
      }
    }
    after[i] = match;
  }

  map<ll,ll> d;
  set<ll> s;
  for (ll i{0}; i < n; ++i) {
    s.insert(i);
  }
  cout << pairingsStuck(0,n/2,d,s) << "\n";

  return 0;
}
