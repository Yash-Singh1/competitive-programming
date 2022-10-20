#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  ll xs[n];
  for (ll i{0}; i < n; ++i) {
    cin >> xs[i];
  }
  ll ys[n];
  for (ll i{0}; i < n; ++i) {
    cin >> ys[i];
  }
  ll ans {-1};
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < n; ++j) {
      if (i != j) {
        ans = max(ans, (ll)pow(abs(xs[j] - xs[i]), 2) + (ll)pow(abs(ys[j] - ys[i]), 2));
      }
    }
  }
  cout << ans;

  return 0;
}
