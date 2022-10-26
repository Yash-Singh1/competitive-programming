#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd( ll a, ll b) {
  if (a == 0 || b == 0) {
    return max(a,b);
  } else if (a > b) {
    return gcd(b,a%b);
  } else {
    return gcd(a,b%a);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  ll a[n];
  for (int i{0}; i<n;++i) {
    cin >> a[i];
  }

  ll p[n], s[n];
  p[0] = a[0];
  s[n-1]=a[n-1];

  for (ll i{1}; i <n;++i) {
    p[i] = gcd(p[i-1],a[i]);
  }

  for (ll i{n-2}; i >= 0; --i) {
    s[i] =gcd(s[i+1],a[i]);
  }

  // for (int i{0}; i < n; ++i){
  //   cout << p[i] << " ";
  // }
  // cout << "\n";

  // for (int i{0}; i < n; ++i){
  //   cout << s[i] << " ";
  // }
  // cout << "\n";

  ll ans{1};
  for (ll i{0}; i<n;++i) {
    ans = max(ans, gcd(i ? p[i-1] : 0, i == n-1 ? 0 : s[i+1]));
  }

  cout << ans << "\n";

  return 0;
}
