#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  ll a[n], b[m];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }
  for (ll i=0; i < m; ++i) {
    cin >> b[i];
  }

  ll alow{0};
  ll blow{0};
  ll ans{0};
  while (alow < n && blow < m) {
    while (a[alow] != b[blow] && alow < n && blow < m) {
      if (a[alow] < b[blow]) {
        ++alow;
      } else if (a[alow] > b[blow]) {
        ++blow;
      }
    }

    if (alow == n || blow == m) break;

    ll anow{a[alow]}, bnow{b[blow]};
    ll adiff{0}, bdiff{0};

    if (a[alow] == b[blow]) {
      while (a[alow] == anow && alow < n){
        ++alow;
        ++adiff;
      }
      while (b[blow] == bnow && blow < m){
        ++blow;
        ++bdiff;
      }
      ans += adiff * bdiff;
    }
  }

  cout << ans;

  return 0;
}
