#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  ll l{1}, r{n*n};
  while (l <= r){
    ll behind{0}, mid{(l+r)/2}, tot{0}, rightafter{n*n};
    bool init{0};
    for (ll i{1}; i <= n; ++i) {
      if (mid%i==0 && (mid/i)<=n) {
        ++tot;
        init=1;
      }
      behind += min(mid/i, n);
      if (mid%i==0 && (mid/i)<=n) {
        --behind;
      }
      rightafter = min(rightafter, ((mid/i) >= n) ? LLONG_MAX : (1+(mid/i))*i);
    }
    if (behind <= ((n*n-1)/2) && behind+(max(0LL,tot-1))>=((n*n-1)/2)) {
      if (!init) {
        l = rightafter;
        r = rightafter;
        continue;
      }
      if (n&1 || behind+(max(0LL,tot-1))>((n*n-1)/2)) {
        cout << mid << "\n";
      } else {
        cout << (mid+rightafter)/2 << "\n";
      }
      return 0;
    } else if (behind < ((n*n-1)/2)) {
      // cout << l << " " << r << " " << behind << " " << tot << " " << ((n*n-1)/2) << "L\n";
      l = mid+1;
    } else {
      // cout << l << " " << r << " " << behind << " " << tot << " " << ((n*n-1)/2) << "R\n";
      r=mid-1;
    }
  }

  return 0;
}
