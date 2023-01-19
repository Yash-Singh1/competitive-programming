#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("superbull.in", "r", stdin);
  freopen("superbull.out", "w", stdout);

  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i{0}; i < n; ++i) cin >> a[i];

  vector<bool> selected(n, 0);
  vector<ll> mn(n);
  mn[0] = 0;
  ll ans{0};
  for (ll i{0}; i < n; ++i) {
    ll v{-1};
    for (ll j{0}; j < n; ++j) {
      if (!selected[j] && (v == -1 || mn[j] > mn[v])) {
        v = j;
      }
    }
    ans += mn[v];
    selected[v] = 1;
    for (ll j{0}; j < n; ++j) {
      if ((a[v]^a[j]) > mn[j]) {
        mn[j] = (a[v]^a[j]);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
