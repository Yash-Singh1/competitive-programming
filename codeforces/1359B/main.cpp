#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;

  ll n, m, x, y;
  while (t--) {
    cin >> n >> m >> x >> y;
    vector<vector<char>> grid(n, vector<char>(m));
    ll sm{0};
    for (ll i{0}; i < n; ++i) {
      for (ll j{0}; j < m; ++j) {
        cin >> grid[i][j];
        if (grid[i][j] == '.') ++sm;
      }
    }
    if (y >= x*2) {
      cout << sm * x << "\n";
      continue;
    }
    sm = 0;
    for (ll i{0}; i < n; ++i) {
      for (ll j{0}; j < m; ++j) {
        if (grid[i][j] == '.') {
          if (j == m - 1 || grid[i][j + 1] == '*') sm += x;
          else {
            ++j;
            sm += y;
          }
        }
      }
    }
    cout << sm << '\n';
  }

  return 0;
}
