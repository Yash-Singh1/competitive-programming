#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll,ll>m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  ll n, g;
  cin >> n >> g;

  map<ll,ll> poscoords;
  pair<ll,pair<ll,ll>> a[n];
  ll coords{0};
  for (ll i{0}; i  < n; ++i) {
    cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    // cout << a[i].second.first << " ";
    if (poscoords.find(a[i].second.first) == poscoords.end()) {
      poscoords[a[i].second.first] = coords;
      a[i].second.first = coords;
      ++coords;
    } else {
      a[i].second.first = poscoords[a[i].second.first];
    }
  }
  sort(a,a+n);

  multiset<ll>s;
  set<ll> posnext;
  for (int i{0}; i < coords; ++i) {
    m[i] = g;
    s.insert(g);
  }

  ll winnerCount{(ll)poscoords.size()};
  ll winnerNum{0};
  ll ans{0};
  ll prev;
  for (ll i{0}; i < n; ++i) {
    if (a[i].second.second == 0) continue;
    prev = m[a[i].second.first];
    // cout << a[i].second.first << " " << m[a[i].second.first] << "\n";
    s.erase(s.find(m[a[i].second.first]));
    m[a[i].second.first] += a[i].second.second;
    s.insert(m[a[i].second.first]);
    ll winners{(ll)s.count(*(--s.end()))};
    // cout << prev << " " << winnerNum << " " << *(--s.end()) << "\n";
    if (winners != winnerCount ||
      (prev == winnerNum && *(--s.end()) != m[a[i].second.first]) ||
      (prev != winnerNum && winnerNum != *(--s.end()))) {
      // cout << a[i].first << " ";
      ++ans;
    }
    winnerNum = *(--s.end());
    winnerCount = winners;
  }

  cout << ans << "\n";

  return 0;
}
