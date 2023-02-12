#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("hayfeast.in", "r", stdin);
  freopen("hayfeast.out", "w", stdout);

  ll n, m;
  cin >> n >> m;

  vector<pll> haybales(n);
  for (int i{0}; i < n; ++i) {
    cin >> haybales[i].first >> haybales[i].second;
  }

  ll flav{0};
  int r{0};
  ll ans{INT_MAX};
  multiset<ll> spice;
  for (int i{0}; i < n; ++i) {
    while (r < n && flav < m) {
      spice.insert(haybales[r].second);
      flav += haybales[r].first;
      ++r;
    }
    if (flav >= m) ans = min(ans, *spice.rbegin());
    spice.erase(spice.find(haybales[i].second));
    flav -= haybales[i].first;
  }

  cout << ans << "\n";

  return 0;
}
