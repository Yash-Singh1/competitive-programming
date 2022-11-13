#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k; 
  cin >> n >> k;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a,a+n);

  ll p[n-(n/2)];
  p[0] = a[n/2];
  for (ll i{n/2+1}; i < n; ++i) {
    p[i-(n/2)] = p[i-(n/2)-1] + a[i];
  }

  ll low{a[n/2]}, high{2000000000}, ans{a[n/2]};
  if ((n & 1) == 0) {
    ans = (ans + a[n/2+1])/2;
  }
  while (low <= high) {
    ll mid{(low+high)/2};
    auto query = upper_bound(a + n/2, a + n, mid);
    ll cost{((ll)(query - (a + n/2)) * (ll)mid) - (ll)p[(query - (a + n/2))-1]};
    if (cost <= k) {
      low = mid+1;
      ans = max(ans, mid);
    } else {
      high = mid-1;
    }
  }

  cout << ans << "\n";

  return 0;
}
