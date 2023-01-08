#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    unordered_set<ll> exist;
    ll x;
    bool yay{1};
    for (ll i{0}; i < n; ++i) {
      cin >> x;
      if (exist.find(x) != exist.end()) {
        cout << "NO\n";
        yay = 0;
        break;
      }
      exist.insert(x);
    }
    if (yay) {
      cout << "YES\n";
    }
  }

  return 0;
}
