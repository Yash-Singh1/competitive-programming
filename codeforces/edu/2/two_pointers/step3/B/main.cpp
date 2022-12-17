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

  ll r{0}, ans{0}, sm{0};
  for (ll l{0}; l < n; ++l) {
    while (r < n && sm + a[r] <= s) {
      sm += a[r];
      ++r;
    }
    ans += (r - l + 1) * (r - l) / 2;
    sm -= a[l];
  }

  cout << ans << "\n";

  return 0;
}
