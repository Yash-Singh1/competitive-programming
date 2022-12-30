#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("king2.in", "r", stdin);
  freopen("king2.out", "w", stdout);

  vector<vector<int>> board(8, vector<int>(8));
  for (int i{0}; i < 8; ++i) {
    for (int j{0}; j < 8; ++j) {
      cin >> board[8 - i - 1][j];
    }
  }

  vector<vector<int>> dp(8, vector<int>(8, INT_MAX));
  dp[0][0] = board[0][0];
  for (int i{0}; i < 8; ++i) {
    for (int j{0}; j < 8; ++j) {
      if (i != 7) {
        dp[i + 1][j] = min(dp[i][j] + board[i + 1][j], dp[i + 1][j]);
      }
      if (j != 7) {
        dp[i][j + 1] = min(dp[i][j] + board[i][j + 1], dp[i][j + 1]);
      }
      if (i != 7 && j != 7) {
        dp[i + 1][j + 1] = min(dp[i][j] + board[i +1][j + 1], dp[i + 1][j + 1]);
      }
    }
  }

  cout << dp[7][7] << "\n";

  return 0;
}
