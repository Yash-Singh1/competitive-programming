#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

inline ll median(ll n, ll a[]) {
  if (n % 2 == 0) {
    return (ll)round((long double)(a[n/2-1] + a[n/2]) / 2);
  } else {
    return a[n/2];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a,a+n);

  ll med{median(n,a)};
  ll cost{0};
  for (ll i{0}; i < n; ++i) {
    cost += abs(a[i] - med);
  }

  cout << cost << "\n";

  return 0;
}
