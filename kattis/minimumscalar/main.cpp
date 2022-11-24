#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  ll ot{t};
  while (t--) {
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (ll i{0}; i < n; ++i) {
      cin >> a[i];
    }
    for (ll i{0}; i < n; ++i) {
      cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n,greater<ll>());
    ll sm{0};
    for (ll i{0}; i < n; ++i) {
      sm += a[i] * b[i];
    }
    cout << "Case #" << ot - t << ": " << sm << "\n";
  }

  return 0;
}
