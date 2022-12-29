#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> dp(n+1, INT_MAX);
  dp[n] = 0;
  int oi;
  for (int i{n}; i > 0; --i) {
    if (dp[i] == INT_MAX) continue;
    oi = i;
    while (oi) {
      if ((oi % 10) > 0) dp[i - oi%10] = min(dp[i - oi%10], dp[i] + 1);
      oi /= 10;
    }
  }

  cout << dp[0] << "\n";

  return 0;
}
