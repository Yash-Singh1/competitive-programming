#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, p;
  cin >> n >> p;

  ll a[n];
  ll tot{0};
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
    tot += a[i];
  }

  ll sm{0}, ans{LLONG_MAX}, r{0};
  ll ansl{-1};
  for (ll i{0}; i < n; ++i) {
    while (r < n*2 && (r < n || (r%n) < i) && sm < (p%tot)) {
      sm += a[(r++)%n];
    }
    if (sm >= (p%tot)) {
      if ((r-i)+(n*(p/tot)) < ans) {
        ans = (r-i)+(n*(p/tot));
        ansl=i+1;
      }
    }
    sm -= a[i];
  }

  cout << ansl << " " << ans << "\n";

  return 0;
}
