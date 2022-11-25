#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll w, h, n;

bool fits(ll x) {
  if ((x/w)*(x/h) >= n) {
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> w >> h >> n;

  ll l{1}, r{1};
  while (!fits(r)) r *= 2;
  while (r > l + 1) {
    ll mid{(l+r)/2};
    if (fits(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << r << "\n";

  return 0;
}
