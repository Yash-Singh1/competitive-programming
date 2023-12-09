
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;

  int n{(int)a.size()}, m{(int)b.size()};
  
  vector<vector<int>> dp(2, vector<int>(m+1));
  for (int i{0}; i <= n; ++i) {
    for (int j{0}; j <= m; ++j) {
      if (i == 0) {
        dp[1][j] = j;
      } else if (j == 0) {
        dp[1][j] = i;
      } else {
        dp[1][j] = min({
          dp[0][j] + 1,
          dp[1][j-1] + 1,
          dp[0][j-1] + (a[i-1] == b[j-1] ? 0 : 1)
        });
      }
    }
    // for (int j{0}; j <= m; ++j) {
    //   cout << dp[1][j] << ' ';
    // }
    // cout << '\n';
    swap(dp[0], dp[1]);
    for (int j{1}; j < m; ++j) {
      dp[1][j] = 0;
    }
  }

  cout << dp[0][m] << '\n';

  return 0;
}
