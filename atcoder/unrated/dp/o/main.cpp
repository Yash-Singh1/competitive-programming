#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & -S)

const int MOD = (int)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  bool pos[n][n];
  char x;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> x;
      if (x == '1') {
        pos[i][j] = 1;
      } else {
        pos[i][j] = 0;
      }
    }
  }

  vector<int> dp(1<<n);
  dp[0] = 1;
  for (int i{1}; i < (1<<n); ++i) {
    int m{i};
    while (m) {
      if (pos[__builtin_popcount(i) - 1][__builtin_ctz(m)]) dp[i] += dp[i - LSOne(m)];
      dp[i] %= MOD;
      m -= LSOne(m);
    }
  }

  cout << dp[(1<<n)-1] << "\n";

  return 0;
}
