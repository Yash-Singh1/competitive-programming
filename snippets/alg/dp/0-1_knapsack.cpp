#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;

  vector<int> w(n);
  vector<int> v(n);
  for (int i{0}; i < n; ++i) cin >> w[i] >> v[i];

  vector<int> dp(s+1), dp2(s+1);
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= s; ++j) {
      dp2[j] = 0;
    }
    for (int j{0}; j <= s; ++j) {
      dp2[j] = max(dp2[j], dp[j]);
      if (w[i] + j <= s) {
        dp2[j + w[i]] = max(dp2[j + w[i]], dp[j] + v[i]);
      }
    }
    swap(dp, dp2);
  }

  int ans{0};
  for (int i{s}; i >= 0; --i) {
    ans = max(ans, dp2[i]);
  }

  cout << ans << '\n';

  return 0;
}
