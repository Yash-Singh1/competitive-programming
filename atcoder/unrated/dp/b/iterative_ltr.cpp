#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> dp(n+1, INT_MAX);
  dp[0] = 0;
  for (int i{0}; i < n; ++i) {
    for (int j{1}; j <= k; ++j) {
      if (i + j >= n) break;
      dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]));
    }
  }

  cout << dp[n-1] << "\n";

  return 0;
}
