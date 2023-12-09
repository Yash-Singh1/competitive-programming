#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> grid(n, vector<int>(m));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m));
  dp[0][0] = 1;

  vector<map<int,int>> mc(m);
  vector<int> p(m);
  for (int i{1}; i < n; ++i) {
    int sm{0};
    for (int j{i-1}; j < m; ++j) {
      dp[i][j] = ((sm - mc[j][grid[i][j]]) + MOD) % MOD;
      sm += p[j];
      sm = (sm + dp[i-1][j]) % MOD;
      p[j] = sm;
      mc[j][grid[i][j]] = (mc[j][grid[i][j]] + dp[i-1][j]) % MOD;
    }
    for (int j{0})
  }

  cout << '\n';
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cout << dp[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';

  cout << dp[n-1][m-1] << '\n';

  return 0;
}
