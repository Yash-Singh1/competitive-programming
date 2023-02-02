#include <bits/stdc++.h>

using namespace std;

class BadNeighbors {
  public:
    int maxDonations(vector <int> donations) {
      vector<vector<vector<int>>> dp(41, vector<vector<int>>(2, vector<int>(2)));
      int n{(int)donations.size()};
      dp[1][0][1] = donations[0];
      dp[1][1][0] = donations[1];
      for (int i{1}; i < n; ++i) {
        if (i == 0) {
        } else if (i + 1 == n - 1) {
            dp[i + 1][0][1] = max(dp[i + 1][0][1], max(dp[i][0][1], dp[i][1][1]));
            dp[i + 1][1][0] = max(dp[i + 1][1][0], dp[i][0][0] + donations[n - 1]);
        } else if (i == n - 1) continue;
        else {
            dp[i + 1][0][0] = max(dp[i + 1][0][0], max(dp[i][0][0], dp[i][1][0]));
            dp[i + 1][0][1] = max(dp[i + 1][0][1], max(dp[i][0][1], dp[i][1][1]));
            dp[i + 1][1][0] = max(dp[i + 1][1][0], dp[i][0][0] + donations[i + 1]);
            dp[i + 1][1][1] = max(dp[i + 1][1][1], dp[i][0][1] + donations[i + 1]);
        }
      }
      int ans{0};
      for (int i{0}; i < n; ++i) ans = max(ans, max(max(dp[i][0][0], dp[i][0][1]), max(dp[i][1][0], dp[i][1][1])));
      return ans;
    }
};
