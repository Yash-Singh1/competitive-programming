#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("sabotage.in", "r", stdin);
  freopen("sabotage.out", "w", stdout);

  int n;
  cin >> n;

  double a[n];
  double tot{0};
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    tot += a[i];
  }

  double l{0}, r{1e5}, ans{-1};
  for (int i{0}; i < 40; ++i) {
    double m{(l+r)/2};
    double sm{0}, mx{INT_MIN};
    for (int i{1}; i < n-1; ++i) {
      sm += a[i] - m;
      if (sm > mx) mx = sm;
      if (sm < 0) sm = 0;
    }
    if (mx >= tot - (m * n)) {
      ans = m;
      r = m;
    } else {
      l = m;
    }
  }

  cout << fixed << setprecision(3) << ans << "\n";

  return 0;
}
