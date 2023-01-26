#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x;
  cin >> n >> x;

  vector<ll> a(n);
  for (ll i{0}; i < n; ++i) cin >> a[i];

  if (n < 4) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  map<ll,pll> m;
  vector<vector<pll>> mx(n);
  for (int i{0}; i < n; ++i) {
    for (int j{i + 1}; j < n; ++j) {
      if (m.find(x - a[i] - a[j]) != m.end()) {
        cout << m[x - a[i] - a[j]].first+1 << " " << m[x - a[i] - a[j]].second+1 << " " << i+1 << " " << j+1 << "\n";
        return 0;
      }
      mx[j].push_back({i, j});
    }
    for (auto &pr: mx[i]) {
      m[a[pr.first] + a[pr.second]] = pr;
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}
