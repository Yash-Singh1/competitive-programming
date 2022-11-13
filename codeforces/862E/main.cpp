#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll closest_in_set(ll &a, set<ll> &s) {
  auto query = s.lower_bound(-a);
  if (query == s.end()) {
    return llabs(*prev(query) + a);
  }
  ll ans{llabs(*query + a)};
  if (query != prev(s.end())) {
    ans = min(ans, llabs(*next(query) + a));
  }
  if (query != s.begin()) {
    ans = min(ans, llabs(*prev(query) + a));
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m, q;
  cin >> n >> m >> q;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }
  ll b[m];
  for (ll i{0}; i < m; ++i) {
    cin >> b[i];
  }

  // for (ll i{0}; i < m; ++i) {
  //   cout << b[i] << " ";
  // }
  // cout << "\n";

  set<ll> optimal;
  ll running{0};
  for (ll i{0}; i < n; ++i) {
    if (i & 1) {
      running += b[i];
    } else {
      running -= b[i];
    }
  }

  for (ll i{0}; i <= m - n; ++i) {
    optimal.insert(running);
    running += b[i];
    running *= -1;
    if ((n + i) < m) {
      if ((n) & 1) {
        running -= b[n+i];
      } else {
        running += b[n+i];
      }
    }
  }

  // for (auto optimality: optimal) {
  //   cout << optimality << " ";
  // }
  // cout << "\n";

  ll sma{0};
  // for (ll i{0}; i < n; ++i) {
  //   a[i] *= (i % 2 == 0 ? 1 : -1);
  // }

  for (ll i{0}; i < n; ++i) {
    sma += a[i] * (((i % 2) == 0) ? 1 : -1);
  }

  // cout << "S" << sma << "\n";

  // ll p[n];
  // p[0] = a[0];
  // for (ll i{0}; i < n; ++i) {
  //   p[i] = a[i] + p[i - 1];
  // }

  cout << llabs(closest_in_set(sma, optimal)) << "\n";

  while (q--) {
    ll l, r, x;
    cin >> l >> r >> x;
    if (((r-l) % 2) == 0) {
      sma += x * ((l & 1) ? 1 : -1);
    }
    // cout << "S" << sma << "\n";
    cout << llabs(closest_in_set(sma, optimal)) << "\n";
  }

  return 0;
}
