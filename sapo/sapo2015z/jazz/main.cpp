#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  vector<vector<int>> dp(501, vector<int>(501));
  for (int i{0}; i < (int)s.size(); ++i) {
    for (int j{0}; j < (int)s.size() - i; ++j) {
      dp[j][i + j] = dp[j + 1][i + j] + 1;
      for (int k{j + 1}; k <= i + j; ++k) {
        if (s[j] == s[k]) {
          dp[j][i + j] = min(dp[j][i + j], dp[j + 1][k - 1] + dp[k + 1][j + i]);
        }
      }
    }
  }

  cout << dp[0][(int)s.size() - 1] << "\n";

  return 0;
}
