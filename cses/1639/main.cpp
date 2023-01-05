#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;
  int dp[a.size() + 1][b.size() + 1];
  for (int i{0}; i <= a.size(); ++i) {
    for (int j{0}; j <= b.size(); ++j) {
      if (i == 0 && j == 0) {
        dp[i][j] = 0;
      } else if (i == 0) {
        dp[i][j] = j;
      } else if (j == 0) {
        dp[i][j] = i;
      } else if (a[i - 1] != b[j - 1]) {
        dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
      } else {
        dp[i][j] = dp[i - 1][j - 1];
      }
    }
  }

  cout << dp[a.size()][b.size()] << "\n";

  return 0;
}
