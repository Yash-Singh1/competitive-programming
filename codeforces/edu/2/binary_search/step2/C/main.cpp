#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x, y;
  cin >> n >> x >> y;
  --n;

  ll l{0}, r{LLONG_MAX - 10}, ans{-1};
  while (l <= r) {
    ll mid{(l+r)/2};
    if ((mid/x)+(mid/y) >= n) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << ans + min(x,y) << "\n";

  return 0;
}
