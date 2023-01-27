#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("threesum.in", "r", stdin);
  freopen("threesum.out", "w", stdout);

  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<ll>> tot(n, vector<ll>(n));
  // to update hashmaps, fix the current index as the mid point and iterate over everything before, set in hashmap
  // to update tot array, iterate over each possible start index and query number of expected hashmap values
  for (int j{0}; j < n; ++j) {
    gp_hash_table<int,int> g({},{},{},{},{1<<13});
    for (int i{j + 1}; i < n; ++i) {
      auto it = g.find(-a[i]-a[j]);
      if (it != g.end()) tot[j][i] += it->second;
      ++g[a[i]];
    }
  }

  for (int i{n - 1}; i >= 0; --i) {
    for (int j{i + 1}; j < n; ++j) {
      tot[i][j] += tot[i + 1][j] + tot[i][j - 1] - tot[i + 1][j - 1]; 
    }
  }

  int x, y;
  while (q--) {
    cin >> x >> y;
    --x; --y;
    cout << tot[x][y] << "\n";
  }

  return 0;
}
