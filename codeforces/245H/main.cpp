#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n{(int)s.size()};
  vector<vector<int>> dp(n, vector<int>(n));
  vector<vector<bool>> pal(n, vector<bool>(n));
  for (int i{0}; i < n; ++i) {
    if (i < n - 1 && s[i] == s[i + 1]) {
      dp[i][i + 1] = 3;
      pal[i][i + 1] = 1;
    }
    else if (i < n - 1) dp[i][i + 1] = 2;
    dp[i][i] = 1;
    pal[i][i] = 1;
  }

  for (int i{2}; i < n; ++i) {
    for (int j{0}; j + i < n; ++j) {
      pal[j][i + j] = pal[j + 1][i + j - 1] && s[j] == s[j + i];
      dp[j][i + j] = dp[j + 1][i + j] + dp[j][i + j - 1] - dp[j + 1][i + j - 1] + pal[j][i + j];
    }
  }

  int q;
  cin >> q;

  int a, b;
  while (q--) {
    cin >> a >> b; --a; --b;
    cout << dp[a][b] << "\n";
  }

  return 0;
}
