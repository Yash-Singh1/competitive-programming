#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  char x;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    if (x == 'H') a[i] = 0;
    else if (x == 'P') a[i] = 1;
    else a[i] = 2;
  }

  vector<vector<vector<int>>> dp(2, vector<vector<int>>(k+1, vector<int>(3)));
  for (int i{1}; i <= n; ++i) {
    for (int j{0}; j <= k; ++j) {
      for (int l{0}; l < 3; ++l) {
        dp[1][j][l] = dp[0][j][l];
        if (j < k) {
          dp[1][j][l] = max({dp[1][j][l], dp[0][j+1][0], dp[0][j+1][1], dp[0][j+1][2]});
        }
        dp[1][j][l] += (a[i-1] == l) ? 1 : 0;
      }
    }
    swap(dp[0], dp[1]);
    for (int j{0}; j <= k; ++j) {
      for (int l{0}; l < 3; ++l) {
        dp[1][j][l] = 0;
      }
    }
  }

  int mx{0};
  for (int i{0}; i <= k; ++i) {
    for (int j{0}; j < 3; ++j) {
      mx = max(mx, dp[0][i][j]);
    }
  }

  cout << mx << '\n';

  return 0;
}
