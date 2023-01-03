// My brain told me I should look for all sums that are >= W, but stop right when that limit is exceeded.
// That would be a reasonable explanation for why the w_i <= 1e6 while W <= 1e3 shouldn't be something to worry about

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ld div(pair<int,int> pii) {
  if (pii.second == 0) return 0;
  return (ld)pii.first / (ld)pii.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("talent.in", "r", stdin);
  freopen("talent.out", "w", stdout);

  int n, w;
  cin >> n >> w;
  vector<int> weight(n);
  vector<int> talent(n);
  for (int i{0}; i < n; ++i) {
    cin >> weight[i] >> talent[i];
  }

  vector<vector<pair<int,int>>> dp(n + 1, vector<pair<int,int>>(w + 1));
  dp[0][0] = {0,0};
  ld ans{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= w; ++j) {
      if (i != 0) {
        if (div(dp[i - 1][j]) > div(dp[i][j])) {
          dp[i][j] = dp[i - 1][j];
        }
      }
      if (div(dp[i][j]) > div(dp[i + 1][j])) {
        dp[i + 1][j] = dp[i][j];
      }
      pair<int,int> proposal{dp[i][j].first + talent[i], dp[i][j].second + weight[i]};
      if (div(proposal) > div(dp[i + 1][min(w, dp[i][j].second + weight[i])])) {
        dp[i + 1][min(w, dp[i][j].second + weight[i])] = proposal;
      }
    }
    ans = max(ans, div(dp[i + 1][w]));
  }

  cout << (int)(ans*1000) << "\n";

  return 0;
}
