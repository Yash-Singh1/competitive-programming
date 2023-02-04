#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  vector<vector<ll>> dp(n, vector<ll>(n));
  for (int i{n - 1}; i >= 0; --i) {
    dp[i][i] = a[i];
    if (i < n-1) dp[i][i + 1] = max(a[i] - a[i + 1], a[i + 1] - a[i]);
    for (int j{i + 2}; j < n; ++j) {
      dp[i][j] = max(min(dp[i + 1][j - 1] - a[j], dp[i + 2][j] - a[i + 1]) + a[i], min(dp[i + 1][j - 1] - a[i], dp[i][j - 2] - a[j - 1]) + a[j]);
    }
  }

  cout << dp[0][n - 1] << "\n";

  return 0;
}
