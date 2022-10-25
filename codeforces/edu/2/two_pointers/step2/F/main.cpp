#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  ll a[n];
  for (ll i{0};i<n;++i) {
    cin >> a[i];
  }

  map<ll,ll>m;
  ll l{0}, tot{0};
  for (ll r{0};r < n;++r) {
    ++m[a[r]];
    while (l<r && m.rbegin()->first - m.begin()->first > k) {
      --m[a[l]];
      if (m[a[l]] == 0) {
        m.erase(a[l]);
      }
      ++l;
    }
    if (m.rbegin()->first - m.begin()->first <= k) {
      tot += r-l+1;
    }
  }

  cout << tot << "\n";

  return 0;
}
