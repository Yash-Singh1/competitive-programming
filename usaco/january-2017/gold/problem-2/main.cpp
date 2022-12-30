#include <bits/stdc++.h>

using namespace std;

map<char, int> m{{'H', 0}, {'P', 2}, {'S', 1}};
int choices[3] {'H', 'S', 'P'};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  vector<char> seq(n);
  for (int i{0}; i < n; ++i) cin >> seq[i];

  // dp[game][switch][type] = max(dp[game - 1][switch - 1][other type], dp[game - 1][switch][type])
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(3, 0)));
  int ans{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= k; ++j) {
      for (int l{0}; l < 3; ++l) {
        int adding{0};
        if (m[seq[i]] == l) {
          ++adding;
        }
        dp[i][j][l] = max((i == 0 ? 0 : dp.at(i - 1).at(j).at(l)), max((i == 0 || j == 0) ? 0 : dp.at(i-1).at(j-1).at(l == 0 ? 1 : (l == 1 ? 2 : 0)), (i == 0 || j == 0) ? 0 : dp.at(i - 1).at(j - 1).at(l == 0 ? 2 : (l == 1 ? 0 : 1)))) + adding;
        ans = max(ans, dp[i][j][l]);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
