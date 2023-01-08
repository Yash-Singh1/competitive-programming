#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, a, b;
  cin >> n >> a >> b;

  vector<ll> arr(n);
  for (ll i{0}; i < n; ++i) {
    cin >> arr[i];
  }

  vector<ll> p(n);
  p[0] = arr[0];
  for (ll i{1}; i < n; ++i) {
    p[i] = arr[i] + p[i - 1];
  }

  multiset<ll> s;
  for (ll i{a - 1}; i < b; ++i) {
    s.insert(p[i]);
  }

  ll ans{LLONG_MIN};
  for (ll l{0}; l < n - a + 1; ++l) {
    ans = max(ans, *s.rbegin() - (l == 0 ? 0 : p[l - 1]));
    if (l + b < n) {
      s.insert(p[l + b]);
    }
    s.erase(s.find(p[l + a - 1]));
  }

  cout << ans << "\n";

  return 0;
}
