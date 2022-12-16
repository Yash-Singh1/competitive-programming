// keep frequency map of all values of b possible from index from c
// for each a, add to sm by the frequency of that value in the stored map

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  ll a[n], b[n], c[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }
  for (ll i{0}; i < n; ++i) {
    cin >> b[i];
  }
  for (ll i{0}; i < n; ++i) {
    cin >> c[i];
  }

  map<ll,ll> f;
  for (ll i{0}; i < n; ++i) {
    ++f[b[c[i] - 1]];
  }

  ll ans{0};
  for (ll i{0}; i < n; ++i) {
    ans += f[a[i]];
  }

  cout << ans << "\n";

  return 0;
}
