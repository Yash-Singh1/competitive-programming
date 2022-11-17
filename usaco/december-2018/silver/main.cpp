#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool val(ll &n, ll &d, ll &m, ll &c, ll a[]) {
  ll busesleft{m};
  ll furthest;
  ll i{0};
  for (; (i < n && busesleft); ++i) {
    furthest = -1;
    for (ll j{i}; j < i+c; ++j) {
      if (a[i]+d < a[j]) {
        break;
      } else {
        furthest = j;
      }
    }
    --busesleft;
    i = furthest;
  }
  // cout << i << " " << d << "\n";
  if (i == n) {
    return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("convention.in", "r", stdin);
  freopen("convention.out", "w", stdout);

  ll n, m, c;
  cin >> n >> m >> c;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a,a+n);

  ll l{0}, r{a[n-1]-a[0]}, ans{-1};
  while (l <= r) {
    ll mid{(l+r)/2};
    if (val(n, mid, m, c, a)) {
      r = mid-1;
      ans = mid;
    } else {
      l = mid+1;
    }
  }

  cout << ans << "\n";

  return 0;
}
