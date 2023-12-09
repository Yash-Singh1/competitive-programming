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

  vector<int> dp(n);
  dp[0] = a[0];
  for (int i{1}; i < n; ++i) {
    int mx{a[i]};
    for (int j{i}; j >= 0 && i-j+1 <= k; --j) {
      mx = max(mx, a[j]);
      if (j) {
        dp[i] = max(dp[i], dp[j-1] + mx*(i-j+1));
      } else {
        dp[i] = max(dp[i], mx*(i-j+1));
      }
    }
  }

  cout << dp[n-1] << '\n';

  return 0;
}
