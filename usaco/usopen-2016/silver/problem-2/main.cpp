#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a,a+n);

  ll l{0};
  ll p[n];
  for (ll r{0}; r < n; ++r) {
    while (l < r && a[l] + k < a[r]) {
      ++l;
    }
    p[r] = r-l+1;
  }

  ll s[n];
  ll r{n-1};
  for (ll i{n-1}; i >= 0; --i) {
    while (r > i && a[r] - k > a[i]) {
      --r;
    }
    s[i] = r-i+1;
  }

  ll ans{0};
  multiset<ll> pq;
  for (ll i{0}; i < n; ++i) {
    pq.insert(s[i]);
  }

  for (ll i{0}; i < n - 1; ++i) {
    pq.erase(pq.find(s[i]));
    ans = max(ans, p[i] + *pq.rbegin());
  }
  ans = max(ans,max(s[0],p[n-1]));

  cout << ans << "\n";

  return 0;
}
