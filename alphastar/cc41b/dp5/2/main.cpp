#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, g;
  cin >> h >> g;

  vector<pii> ch(h), cg(g);
  for (int i{0}; i < h; ++i) {
    cin >> ch[i].first >> ch[i].second;
  }
  for (int i{0}; i < g; ++i) {
    cin >> cg[i].first >> cg[i].second;
  }

  vector<vector<vector<int>>> dp(h+1, vector<vector<int>>(g+1, vector<int>(2, INT_MAX)));
  dp[1][0][0] = 0;
  for (int i{0}; i <= h; ++i) {
    for (int j{0}; j <= g; ++j) {
      for (int k{0}; k < 2; ++k) {
        if (dp[i][j][k] == INT_MAX) continue;
        pii cur = (k == 0 ? ch[i-1] : cg[j-1]);
        if (i < h) {
          dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k] + (int)pow(ch[i].first - cur.first, 2) + (int)pow(ch[i].second - cur.second, 2));
        }
        if (j < g) {
          dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][k] + (int)pow(cg[j].first - cur.first, 2) + (int)pow(cg[j].second - cur.second, 2));
        }
      }
    }
  }

  cout << dp[h][g][0] << '\n';

  return 0;
}
