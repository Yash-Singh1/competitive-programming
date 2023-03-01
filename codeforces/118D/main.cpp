#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e8;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;

  vector<vector<vector<vector<int>>>> dp(n1+1, vector<vector<vector<int>>>(n2+1, vector<vector<int>>(11, vector<int>(2))));
  dp[n1][n2][0][0] = 1;

  int ans{0};
  for (int i{n1}; i >= 0; --i) {
    for (int j{n2}; j >= 0; --j) {
      for (int l{0}; l < 2; ++l) {
        for (int m{0}; m <= (l?k2:k1); ++m) {
          if (l) {
            if (m < k2 && j) {
              dp[i][j-1][m+1][l] += dp[i][j][m][l];
              dp[i][j-1][m+1][l] %= MOD;
            }
            if (i) {
              dp[i-1][j][1][0] += dp[i][j][m][l];
              dp[i-1][j][1][0] %= MOD;
            }
          } else {
            if (m < k1 && i) {
              dp[i-1][j][m+1][l] += dp[i][j][m][l];
              dp[i-1][j][m+1][l] %= MOD;
            }
            if (j) {
              dp[i][j-1][1][1] += dp[i][j][m][l];
              dp[i][j-1][1][1] %= MOD;
            }
          }
          if (!i && !j) {
            ans += dp[i][j][m][l];
            ans %= MOD;
          }
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
