#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  bool rowed[n], colled[n];
  ll rows{0}, cols{0};
  for (ll i{0}; i < n; ++i) {
    rowed[i] = 0;
    colled[i] = 0;
  }

  ll engaged{0};
  ll x, y;
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    if (rowed[x] && colled[y]) {}
    else if (!rowed[x] && !colled[y]) {
      rowed[x] = 1;
      colled[y] = 1;
      engaged += 2*n - 1 - cols - rows;
      ++rows; ++cols;
    } else if (rowed[x] && !colled[y]) {
      colled[y] = 1;
      engaged += n - rows;
      ++cols;
    } else if (colled[y] && !rowed[x]) {
      rowed[x] = 1;
      engaged += n - cols;
      ++rows;
    }
    cout << (n*n) - engaged << " ";
  }
  cout << "\n";

  return 0;
}
