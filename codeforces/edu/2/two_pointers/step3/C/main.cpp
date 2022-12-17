#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, d;
  cin >> n >> d;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }

  ll r{0};
  ll ans{0};
  for (ll l{0}; l < n; ++l) {
    while (r < n && a[r] <= a[l] + d) {
      ++r;
    }
    ans += n - r;
  }

  cout << ans << "\n";

  return 0;
}
