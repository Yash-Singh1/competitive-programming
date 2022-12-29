#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  int dp[n];
  dp[0] = 0;
  for (int i{1}; i < n; ++i) {
    dp[i] = INT_MAX;
    if (i - 1 >= 0) {
      dp[i] = dp[i - 1] + abs(a[i - 1] - a[i]);
    }
    if (i - 2 >= 0) {
      dp[i] = min(dp[i], dp[i - 2] + abs(a[i - 2] - a[i]));
    }
  }

  cout << dp[n-1] << "\n";

  return 0;
}
