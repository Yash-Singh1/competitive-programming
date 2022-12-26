#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<ll> a(n), b(n);
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }
  for (ll i{0}; i < n; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans{1};
  for (ll i{0}; i < n; ++i) {
    ans *= (ll)(upper_bound(a.begin(), a.end(), b[i]) - a.begin()) - i;
  }

  cout << ans << "\n";

  return 0;
}
