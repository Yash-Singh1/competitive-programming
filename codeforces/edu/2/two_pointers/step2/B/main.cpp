#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, s;
  cin >> n >> s;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }

  ll ans{LLONG_MAX}, sm{0}, r{0};
  for (ll l{0}; l < n; ++l) {
    while (r < n && sm < s) {
      sm += a[r++];
    }
    if (sm >= s) {
      ans = min(r-l,ans);
    }
    sm -= a[l];
  }

  cout << (ans==LLONG_MAX?-1:ans);

  return 0;
}
