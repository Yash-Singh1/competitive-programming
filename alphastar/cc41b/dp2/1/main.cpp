#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> val(n, vector<int>(m));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> val[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m));
  dp[0][0] = 1;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      for (int l{i+1}; l < n; ++l) {
        for (int o{j+1}; o < m; ++o) {
          if (val[i][j] != val[l][o]) {
            dp[l][o] = (dp[l][o] + dp[i][j]) % MOD;
          }
        }
      }
    }
  }

  cout << dp[n-1][m-1] << '\n';

  return 0;
}
