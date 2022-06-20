// Iterative DP

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> dp(1000005, 0);
  dp[0] = 1;
  for (int i{1}; i <= n; ++i) {
    for (int j{1}; j <= 6 && i >= j; ++j) {
        dp[i] += dp[i - j];
        dp[i] %= 1000000007;
    }
  }
  cout << dp[n];
}
