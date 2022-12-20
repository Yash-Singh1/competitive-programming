#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  ll ans{0};
  for (ll i{2}; i * i <= n; ++i) {
    ll tot{0};
    ll sub{1};
    while (n % i == 0) {
      ll on{n};
      for (ll j{0}; j < sub; ++j) {
        n /= i;
        if (n % i != 0 && j < sub - 1) {
          // cout << n << " " << i << " " << sub << " " << tot << " " << ans << "\n";
          ans += tot;
          goto end;
        }
      }
      ++tot;
      ++sub;
    }
    ans += tot;
    end: continue;
  }
  if (n > 1) ++ans;

  cout << ans << "\n";

  return 0;
}
