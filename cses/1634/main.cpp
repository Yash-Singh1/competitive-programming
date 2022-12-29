#include <bits/stdc++.h>

using namespace std;

vector<int> dp((int)1e6+5);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i{0}; i < n; ++i) {
    cin >> coins[i];
  }

  dp[0] = 0;
  for (int i{1}; i <= x; ++i) {
    dp[i] = INT_MAX;
    for (auto &coin: coins) {
      if (coin <= i && dp[i - coin] != INT_MAX) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  cout << (dp[x]==INT_MAX?-1:dp[x]) << "\n";

  return 0;
}
