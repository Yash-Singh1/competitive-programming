#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("palpath.in", "r", stdin);
  freopen("palpath.out", "w", stdout);

  int n;
  cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(n, vector<ll>(n)));
  for (int i{0}; i < n; ++i) {
    dp[0][i][i] = 1;
  }
  int cur{0};
  int r1c{0}, r2c{0}, c1c{0}, c2c{0};
  for (int i{0}; i < n-1; ++i) {
    for (int j{n - 1}; j >= 0; --j) {
      int col1{n - 1 - i - j};
      for (int k{0}; k < n; ++k) {
        int col2{n - 1 - ((n - 1 - i) - (n - 1 - k))};
        for (int l{0}; l < 4; ++l) {
          r1c = 0; r2c = 0; c1c = 0; c2c = 0;
          if ((l & 1)) {
            if (col1) {
              c1c = 1;
            } else continue;
          } else {
            if (j) {
              r1c = 1;
            } else continue;
          }
          if ((l & 2)) {
            if (col2 < n - 1) {
              c2c = 1;
            } else continue;
          } else {
            if (k < n - 1) {
              r2c = 1;
            } else continue;
          }
          if (grid[j - r1c][col1 - c1c] == grid[k + r2c][col2 + c2c]) {
            dp[1 - cur][j - r1c][k + r2c] += dp[cur][j][k];
            if (dp[1 - cur][j - r1c][k + r2c] >= MOD) dp[1 - cur][j - r1c][k + r2c] -= MOD;
          }
        }
        dp[cur][j][k] = 0;
      }
    }
    cur = 1 - cur;
  }

  cout << dp[(n - 1)&1][0][n - 1] << "\n";

  return 0;
}
