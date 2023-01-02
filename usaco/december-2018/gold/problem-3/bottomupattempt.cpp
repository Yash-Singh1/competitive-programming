#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("teamwork.in", "r", stdin);
  freopen("teamwork.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  vector<int> seq(n);
  for (int i{0}; i < n; ++i) cin >> seq[i];

  // groups left, evaluating cow, {tot sum, {cur group mx, ppl in}}
  vector<vector<pair<int,pair<int,int>>>> dp(k, vector<pair<int,pair<int,int>>>(n));
  int ans{0};
  for (int i{k - 1}; i >= 0; --i) {
    for (int j{0}; j < n; ++j) {
      bool newmx{0};
      if (j == 0 && seq[j] > dp[i][j - 1].second.first) {
        newmx = 1;
      }
      if ((j == 0 ? 0 : (dp[i][j - 1].first + (newmx ? seq[j] : dp[i][j - 1].second.first) * (dp[i][j - 1].second.second + 1))) > (i == k - 1 ? 0 : (dp[i + 1][j].second.first * dp[i + 1][j].second.second + dp[i + 1][j].first + seq[j]))) {
        dp[i][j].first = dp[i][j - 1].first;
        dp[i][j].second = {(newmx ? seq[j] : dp[i][j - 1].second.first), dp[i][j - 1].second.second + 1};
      } else {
        if (i != k - 1) dp[i][j].first = dp[i + 1][j].second.first * dp[i + 1][j].second.second + dp[i + 1][j].first;
        else dp[i][j].first = 0;
        dp[i][j].second.first = seq[j];
        dp[i][j].second.second = 1;
      }
      ans = max(ans, dp[i][j].first + dp[i][j].second.first * dp[i][j].second.second);
    }
  }

  cout << ans << "\n";

  return 0;
}
