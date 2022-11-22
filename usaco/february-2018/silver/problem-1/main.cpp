#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("reststops.in", "r", stdin);
  freopen("reststops.out", "w", stdout);

  ll l, n, rf, rb;
  cin >> l >> n >> rf >> rb;

  pair<ll,ll>a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a,a+n,greater<pair<ll,ll>>());

  ll aim{0}, pb{0}, pf{0}, ans{0};
  while (true) {
    ans += (((a[aim].second - pf) * rf) - ((a[aim].second - pb) * rb)) * a[aim].first;
    pb = a[aim].second;
    pf = pb;
    aim = -1;
    for (ll i{aim+1}; i < n; ++i) {
      if (a[i].second > pb) {
        aim = i;
        break;
      }
    }
    if (aim == -1) {
      break;
    }
  }

  cout << ans << "\n";

  return 0;
}
