#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  ll a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a+n);

  ll l{0}, r{a[n-1]-a[0]}, ans{-1};
  ll cleft;
  while (l <= r) {
    cleft = k-1;
    ll mid{(l+r)/2};
    ll lst{a[0]};
    ll lsti{0};
    for (ll i{0}; (i < n && cleft >= 0); ++i) {
      if (a[i] > lst+(2*mid)) {
        --cleft;
        lst = a[i];
      }
      lsti = i;
    }
    if (lsti == n-1 && cleft >= 0) {
      r = mid-1;
      ans = mid;
    } else {
      l = mid+1;
    }
  }

  cout << ans << "\n";

  return 0;
}
