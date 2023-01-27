#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;

  vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1)), dpp(s.size()+1, vector<int>(t.size()+1));
  for (int i{0}; i <= (int)s.size(); ++i) {
    for (int j{0}; j <= (int)t.size(); ++j) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        dpp[i][j] = -1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if (dp[i - 1][j] > dp[i][j - 1]) {
          dpp[i][j] = -2;
        } else {
          dpp[i][j] = -3;
        }
      }
    }
  }

  pair<int,int> cur{s.size(), t.size()};
  string ans;
  while (cur.first && cur.second) {
    if (dpp[cur.first][cur.second] == -2) {
      --cur.first;
    } else if (dpp[cur.first][cur.second] == -3) {
      --cur.second;
    } else {
      ans += s[cur.first - 1];
      --cur.first;
      --cur.second;
    }
  }

  reverse(ans.begin(), ans.end());
  for (auto &ch: ans) cout << ch;
  cout << "\n";

  return 0;
}
