#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  unordered_map<int,int> l, r;
  for (int i{0}; i < (1<<(n/2)); ++i) {
    ll sm{0};
    for (int j{0}; j < (n/2); ++j) {
      if (i & (1<<j)) sm += a[j];
    }
    if (sm <= x) ++l[sm];
  }
  ll ans{0};
  for (int i{0}; i < (1<<(n-(n/2))); ++i) {
    ll sm{0};
    for (int j{n/2}; j < n; ++j) {
      if (i & (1<<(j-(n/2)))) sm += a[j];
    }
    if (sm <= x) {
      // cout << sm << " " << x - sm << "\n";
      ans += l[x - sm];
    }
  }
  // for (auto it = l.begin(); it != l.end(); it = next(it)) {
  //   // cout << it->first << " " << it->second << "\n";
  //   ans += (ll)it->second * r[x - it->first];
  // }
  cout << ans << "\n";

  return 0;
}
