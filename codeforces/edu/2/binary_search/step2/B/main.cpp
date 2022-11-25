#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, k;
ll a[10000];

bool cuts(ld length) {
  ll sm{0};
  for (ll i{0}; i < n; ++i) {
    sm += floor(a[i] / length);
  }
  return sm >= k;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }

  ld l{0.0L}, r{1e8L};
  for (int i{0}; i < 100; ++i) {
    ld m{(l+r)/2};
    if (cuts(m)) {
      l = m;
    } else {
      r = m;
    }
  }

  cout << setprecision(20) << r << "\n";

  return 0;
}
