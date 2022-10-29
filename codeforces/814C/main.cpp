#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q;
  cin >> n;

  string s;
  cin >> s >> q;

  while (q--) {
    ll ans{0}, r{0}, notfav{0}, can;
    char fav;
    cin >> can >> fav;
    for (ll l{0}; l < n; ++l) {
      while (r < n && notfav < can) {
        if (s[r] != fav) {
          ++notfav;
        }
        ++r;
      }
      while (r < n && s[r] == fav) {
        ++r;
      }
      ans = max(ans, r - l);
      if (s[l] != fav) {
        --notfav;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
