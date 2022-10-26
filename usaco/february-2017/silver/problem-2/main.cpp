#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("maxcross.in", "r", stdin);
  freopen("maxcross.out", "w", stdout);

  ll n, k, b;
  cin >> n >> k >> b;

  ll p[n];
  for (ll i{0}; i < n; ++i) {
    p[i] = 0;
  }

  for (ll i{0}; i < b; ++i) {
    ll x;
    cin >> x;
    ++p[x-1];
  }

  for (ll i{1}; i < n; ++i) {
    p[i] += p[i-1];
  }

  ll ans{LLONG_MAX};
  for (ll i{k-1}; i < n; ++i) {
    ans = min(ans, p[i] - ((i - k)>0?p[(i - k)]:0));
  }

  cout << ans << "\n";

  return 0;
}
