#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool val(pair<ll,ll>a[], ll &m, ll &n, ll &d) {
  ll left{n};
  ll last{-1};
  for (ll i{0}; i < m; ++i) {
    if (left == 0) {
      break;
    }
    if (last < 0) {
      last = a[i].first;
    } else {
      if (last+d > a[i].second) continue;
      last = max(a[i].first, last+d);
    }
    --left;
    while (left > 0 && last + d <= a[i].second) {
      last += d;
      --left;
    }
  }
  if (left > 0) {
    return 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("socdist.in", "r", stdin);
  freopen("socdist.out", "w", stdout);

  ll n, m;
  cin >> n >> m;

  pair<ll,ll>a[m];
  for (ll i{0}; i < m; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a,a+m);

  ll l{1}, r{1000000000000000000}, ans{1};
  while (l <= r) {
    ll mid{(r+l)/2};
    if (val(a, m, n, mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid -1;
    }
  }

  cout << ans << "\n";

  return 0;
}
