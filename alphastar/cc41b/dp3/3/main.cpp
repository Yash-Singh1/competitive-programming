#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;

  int n{(int)a.size()}, m{(int)b.size()};
  
  vector<vector<int>> dp(2, vector<int>(m+1));
  for (int i{1}; i <= n; ++i) {
    for (int j{1}; j <= m; ++j) {
      if (a[i-1] == b[j-1]) {
        dp[1][j] = dp[0][j-1] + 1;
      } else {
        dp[1][j] = max(dp[0][j], max(dp[0][j], dp[1][j-1]));
      }
    }
    swap(dp[0], dp[1]);
    for (int j{0}; j <= m; ++j) {
      dp[1][j] = 0;
    }
  }

  cout << dp[0][m] << '\n';

  return 0;
}
