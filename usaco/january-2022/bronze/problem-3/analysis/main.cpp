#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    ll a[n];
    for (ll i{0}; i < n; ++i) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }
    ll cur{1}, moves{0};
    bool fail{0};
    ll fs{a[0]};
    while (cur < n) {
      if (a[cur] < fs) {
        if (cur & 1) {
          fail = 1;
          break;
        } else {
          moves += cur * (fs - a[cur]);
          fs = a[cur];
        }
      } else if (a[cur] > fs) {
        if (cur == n - 1) {
          fail = 1;
          break;
        } else {
          a[cur + 1] -= a[cur] - fs;
          if (a[cur + 1] < 0) {
            fail = 1;
            break;
          }
          moves += 2 * (a[cur] - fs);
        }
      }
      ++cur;
    }
    if (!fail && fs >= 0) {
      cout << moves << "\n";
    } else {
      cout << -1 << "\n";
    }
  }

  return 0;
}
