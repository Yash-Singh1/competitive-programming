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

  vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MAX));
  vector<ll> p(n); p[0] = a[0];
  for (int i{1}; i < n; ++i) {
    p[i] = a[i] + p[i - 1];
  }

  for (int i{n - 1}; i >= 0; --i) {
    dp[i][i] = 0;
    for (int j{i + 1}; j < n; ++j) {
      for (int k{i + 1}; k <= j; ++k) {
        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j] + p[j] - (i ? p[i - 1] : 0));
      }
    }
  }

  cout << dp[0][n - 1] << "\n";

  return 0;
}
