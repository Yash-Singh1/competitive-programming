#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000000+9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, d;
  cin >> n >> d;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }

  sort(a,a+n,greater<ll>());

  ll r{0}, ans{1};
  for (ll l{0}; l < n; ++l) {
    while (r < n && a[l] - d <= a[r]) {
      ++r;
    }
    ans *= (r-l)%mod;
    ans %= mod;
  }

  cout << ans << "\n";

  return 0;
}
