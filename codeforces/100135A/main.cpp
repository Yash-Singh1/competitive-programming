#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("ladder.in", "r", stdin);
  freopen("ladder.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> dp(n+1, INT_MIN);
  dp[0] = 0;
  for (int i{0}; i < n; ++i) {
    dp[i + 1] = max(dp[i + 1], dp[i] + a[i]);
    if (i < n - 1) {
      dp[i + 2] = max(dp[i + 2], dp[i] + a[i + 1]);
    }
  }

  cout << dp[n] << "\n";

  return 0;
}
