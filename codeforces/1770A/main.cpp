#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> a(100);
vector<ll> b(100);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("A.in", "r", stdin);
  // freopen("A.out", "w", stdout);

  ll t;
  cin >> t;

  while (t--) {
    ll n, m;
    cin >> n >> m;
    ll sm{0};
    for (ll i{0}; i < n; ++i) {
      cin >> a[i];
      sm += a[i];
    }
    for (ll i{0}; i < m; ++i) cin >> b[i];
    // for (auto &c: b) {
    //   cout << c << " ";
    // }
    // cout << "\n";
    sort(b.begin(), b.begin() + m);
    sort(a.begin(), a.begin() + n);
    ll j{0};
    // cout << m - 1 << " " << m - 1 - n << " " << sm << "\n";
    for (ll i{m - 1}; i >= 0 && i > m - 1 - n; --i) {
      if (b[i] > a[j]) {
        // cout << "here" << "  " << b[i] << " " << a[j] << "\n";
        sm += b[i] - a[j];
        ++j;
      } else {
        // cout << "here now" << " " << b[i] << " " << a[j] << "\n";
        sm -= a[j] - b[i];
        ++j;
      }
    }
    cout << sm << "\n";
  }

  return 0;
}
