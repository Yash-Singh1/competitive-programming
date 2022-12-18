#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t, h, c, n;
  cin >> t;

  while (t--) {
    cin >> h >> c >> n;
    ll l{1}, r{1000000000}, ans{-1};
    ld ansd{1e6*2};
    while (l <= r) {
      ll mid{(l+r)/2};
      ld calc{(ld)(mid*(c+h)+h)/(2*mid+1)};
      if (calc <= n) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
      if (abs(calc - n) < ansd) {
        ansd = abs(calc - n);
        ans = mid;
      }
    }
    if (abs(n - (c+h)/2) <= ansd && ans != 1) {
      cout << 2 << "\n";
      continue;
    }
    if (abs(n-h) <= ansd) {
      cout << 1 << "\n";
      continue;
    }
    cout << ans * 2 + 1 << "\n";
  }

  return 0;
}
