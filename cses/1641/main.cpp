#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x;
  cin >> n >> x;

  pair<ll, ll> a[n];
  for (ll i{0}; i < n; ++i)
  {
    cin >> a[i].first;
    a[i].second = i+1;
  }

  sort(a, a + n);

  ll ans[3];
  for (ll i{0}; i < n; ++i) {
    ll l{0}, r{n-1};
    while (l<r) {
      if (a[l].first+a[r].first+a[i].first==x) {
        if (l==i) {
          ++l;
        } else if (r==i) {
          --r;
        } else {
          ans[0]=a[l].second;ans[1]=a[r].second;
          ans[2]=a[i].second;
          sort(ans,ans+3);
          cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
          return 0;
        }
      } else if (a[i].first+a[r].first+a[l].first<x) {
        ++l;
      } else {
        --r;
      }
    }
  }
  cout << "IMPOSSIBLE\n";

  return 0;
}
