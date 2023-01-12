#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m, q;
  cin >> n >> m >> q;

  vector<vector<ll>> d(n, vector<ll>(n, LLONG_MAX));
  for (ll i{0}; i < n; ++i) {
    d[i][i] = 0;
  }

  ll x, y, z;
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    d[x][y] = min(d[x][y], z);
    d[y][x] = min(d[y][x], z);
  }

  for (ll k{0}; k < n; ++k) {
    for (ll i{0}; i < n; ++i) {
      for (ll j{0}; j < n; ++j) {
        if (d[i][k] < LLONG_MAX && d[k][j] < LLONG_MAX)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  while (q--) {
    cin >> x >> y;
    --x; --y;
    if (d[x][y] == LLONG_MAX) {
      cout << -1 << "\n";
    } else {
      cout << d[x][y] << "\n";
    }
  }

  return 0;
}
