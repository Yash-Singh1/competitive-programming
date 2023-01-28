#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> a(3);

  // resubmission comment due to rand runtime error
  int n;
  cin >> n >> a[0] >> a[1] >> a[2];

  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  for (int i{0}; i < n; ++i) {
    if (dp[i] == -1) continue;
    for (auto &x: a) {
      if (i + x <= n)
        dp[i + x] = max(dp[i] + 1, dp[i + x]);
    }
  }

  cout << dp[n] << "\n";

  return 0;
}
