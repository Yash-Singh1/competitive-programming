#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);

  ll n;
  cin >> n;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a,a+n);

  ll d[n];
  ll ld{0};
  for (ll i{1}; i < n; ++i) {
    if (a[i] - a[i - 1] != 1) {
      d[ld] = a[i] - a[i - 1] - 1;
      ++ld;
    }
  }

  ll d2[n];
  for (int i{0}; i < ld; ++i) {
    d2[i] = d[i];
  }

  // for (auto &g: d) {
  // cout << g << " ";
  // }
  // cout << "\n";

  set<pair<ll,ll>> s;
  for (ll i{0}; i < ld; ++i) {
    s.insert({d[i], i});
  }

  ll tot{0};
  ll l{0},r{ld-1};
  while (!s.empty()) {
    while (d[l] == 0) ++l;
    while (d[r] == 0) --r;
    ll *shifter;
    if (d[l] > d[r]) {
      shifter = &l;
    } else {
      shifter = &r;
    }
    if (l != r) {
      s.erase({d[*shifter], *shifter});
      if (d[l] > d[r]) ++(*shifter);
      else {
        --(*shifter);
      }
    }
    if (s.empty()) break;
    auto decrementation = --s.end();
    pair<ll, ll> val = *decrementation;
    s.erase(decrementation);
    --val.first;
    --d[val.second];
    if (val.first > 0) {
      s.insert(val);
    }
    ++tot;
  }

  cout << tot << "\n";

  tot = 0;
  l = 0;
  r = ld - 1;
  for (ll i{0}; i < ld; ++i) {
    s.insert({d2[i], i});
  }
  while (!s.empty()) {
    while (d2[l] == 0) ++l;
    while (d2[r] == 0) --r;
    ll *shifter;
    if (d2[l] < d2[r]) {
      shifter = &l;
    } else {
      shifter = &r;
    }
    if (l != r) {
      s.erase({d2[*shifter], *shifter});
      if (d2[l] < d2[r]) ++(*shifter);
      else {
        --(*shifter);
      }
    }
    if (s.empty()) break;
    auto decrementation = --s.end();
    pair<ll, ll> val = *decrementation;
    s.erase(decrementation);
    --val.first;
    --d2[val.second];
    if (val.first > 0) {
      s.insert(val);
    }
    ++tot;
  }

  cout << tot << "\n";

  return 0;
}
