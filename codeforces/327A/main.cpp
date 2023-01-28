#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  int tot{0};
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    if (a[i]) ++tot;
  }

  vector<vector<int>> dp(n, vector<int>(n));
  int ans{0};
  for (int i{0}; i < n; ++i) {
    dp[i][i] = a[i] ? tot - 1 : tot + 1;
    ans = max(dp[i][i], ans);
  }

  for (int i{n - 1}; i >= 0; --i) {
    for (int j{i + 1}; j < n; ++j) {
      dp[i][j] = max(dp[i + 1][j] + (a[i] ? -1 : 1), dp[i][j - 1] + (a[j] ? -1 : 1));
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << "\n";

  return 0;
}
