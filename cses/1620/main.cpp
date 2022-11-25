#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, t;
  cin >> n >> t;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }

  ll l{1}, r{(ll)1e18}, ans{-1};
  while (l <= r) {
    ll sm{0}, mid{(r+l)/2};
    for (ll i{0}; i < n; ++i) {
      sm += mid / a[i];
      if (sm >= t) break;
    }
    if (sm >= t) {
      r = mid-1;
      ans = mid;
    } else {
      l = mid+1;
    }
  }

  cout << ans << "\n";

  return 0;
}
