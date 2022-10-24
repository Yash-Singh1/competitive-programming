#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, s;
  cin >> n >> s;

  ll a[n];

  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }

  ll r{0};
  ll sm{0}, ans{0};
  for (ll i{0}; i < n; ++i) {
    // cout << sm << "\n";
    while (r < n && sm <= s) {
      sm += a[r++];
    }
    if (sm > s) {
      sm -= a[--r];
    }
    // cout << sm << "\n";
    if (sm <= s) {
      // cout << i << " " << r << " " << r-i << "\n";
      ans += r-i;
    } else {
      // cout << "FAIL: " << i << " " << r << " " << sm << "\n";
    }
    sm -= a[i];
  }
  cout << ans;

  return 0;
}
