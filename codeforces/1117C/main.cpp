#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x1, y1, x2, y2, n;
  cin >> x1 >> y1 >> x2 >> y2 >> n;

  char x;
  pair<ll,ll> spec[n];
  for (ll i{0}; i < n; ++i) {
    cin >> x;
    if (x == 'U') {
      spec[i] = {0, 1};
    } else if (x == 'D') {
      spec[i] = {0, -1};
    } else if (x == 'L') {
      spec[i] = {-1, 0};
    } else {
      spec[i] = {1, 0};
    }
  }

  pair<ll,ll> net[n];
  net[0] = spec[0];
  for (ll i{1}; i < n; ++i) {
    net[i] = {net[i - 1].first + spec[i].first, net[i - 1].second + spec[i].second};
  }

  ll l{0}, r{n * (ll)3e9}, ans{-1};
  while (l <= r) {
    ll m{(r+l)/2};
    pair<ll,ll> pos{x1+(m/n)*net[n-1].first, y1+(m/n)*net[n-1].second};
    for (int i{0}; i < m%n; ++i) {
      pos.first += spec[i].first;
      pos.second += spec[i].second;
    }
    if (m >= abs(pos.first - x2) + abs(pos.second - y2)) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }

  cout << ans << "\n";

  return 0;
}
