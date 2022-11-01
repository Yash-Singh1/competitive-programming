#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);

  ll n;
  cin >> n;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a,a+n);

  ll r{0}, ansmin{0};
  if (a[n-2] - a[0] == n - 2 && a[n-1] - a[n-2] > 2 || a[n - 1] - a[1] == n - 2 && a[1] - a[0] > 2) {
    cout << 2 << "\n";
  } else {
    for (ll l{0}; l < n; ++l) {
      while (r < n && a[l]+n > a[r]) {
        ++r;
      }
      ansmin = max(r-l,ansmin);
    }
    cout << n-ansmin << "\n";
  }

  cout << max(a[n-2] - a[0], a[n - 1] - a[1]) - (n - 2) << "\n";

  return 0;
}
