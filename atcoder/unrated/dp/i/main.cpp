#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  cout << fixed << setprecision(12);

  vector<ld> p(n);
  for (int i{0}; i < n; ++i) cin >> p[i];

  vector<vector<ld>> dp(n+1, vector<ld>(n+1));
  dp[0][0] = 1;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= i; ++j) {
      dp[i + 1][j + 1] += dp[i][j] * p[i];
      dp[i + 1][j] += dp[i][j] * (1 - p[i]);
    }
  }

  ld ans{0};
  for (int i{((n+1)/2)}; i <= n; ++i) {
    ans += dp[n][i];
  }

  cout << ans << "\n";

  return 0;
}
