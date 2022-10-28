#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pairup.in", "r", stdin);
  freopen("pairup.out", "w", stdout);

  ll n;
  cin >> n;

  pair<ll,ll>a[n];

  for (int i{0}; i < n; ++i) {
    cin >> a[i].second >> a[i].first;
  }

  sort(a,a+n);

  pair<ll,ll>l{0,0},r{n-1,a[n-1].second-1};
  ll ans{0};
  while ((l.first < r.first || l.second < r.second)) {
    ans = max(ans,a[l.first].first+a[r.first].first);
    ++l.second;
    --r.second;
    if (l.second >= a[l.first].second) {
      ++l.first;
      l.second=0;
    }
    if (r.second<0) {
      --r.first;
      r.second=a[r.first].second-1;
    }
  }

  cout << ans << "\n";

  return 0;
}
