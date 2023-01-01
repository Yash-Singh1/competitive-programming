#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<int> price(1000);
vector<int> pages(1000);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> x;

  vector<vector<int>> dp(n + 1, vector<int>(x + 1));
  for (int i{0}; i < n; ++i) {
    cin >> price[i];
  }
  for (int i{0}; i < n; ++i) {
    cin >> pages[i];
  }

  int ans{0};
  // bottom-up because recalling recursive func causes TLE
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= x; ++j) {
      dp[i][j] = (i == 0 ? 0 : dp[i - 1][j]);
      if (price[i] <= j) {
        dp[i][j] = max(dp[i][j], (i == 0 ? 0 : dp[i - 1][j - price[i]]) + pages[i]);
      }
    }
  }

  cout << dp[n - 1][x] << "\n";

  return 0;
}
