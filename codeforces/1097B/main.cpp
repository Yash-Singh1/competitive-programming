#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> rot(n);
  for (int i{0}; i < n; ++i) cin >> rot[i];

  vector<vector<bool>> dp(n+1, vector<bool>(360));
  dp[0][0] = 1;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < 360; ++j) {
      if (!dp[i][j]) continue;
      for (int k{-1}; k <= 1; k += 2) {
        dp[i + 1][((j + k * rot[i]) + 360) % 360] = 1;
      }
    }
  }

  cout << (dp[n][0] ? "YES" : "NO") << "\n";

  return 0;
}
