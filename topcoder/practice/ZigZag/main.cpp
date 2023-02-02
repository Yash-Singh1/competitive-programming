#include <bits/stdc++.h>

using namespace std;

class ZigZag {
  public:
    int longestZigZag(vector <int> sequence) {
        vector<vector<int>> dp(1001, vector<int>(2, 0));
        int ans{0};
        for (int i{0}; i < sequence.size(); ++i) {
            dp[sequence[i]][0] = max(dp[sequence[i]][0], 1);
            dp[sequence[i]][1] = max(dp[sequence[i]][1], 1);
            for (int j{1}; j <= 1000; ++j) {
                if (j != sequence[i]) {
                    if (j < sequence[i]) {
                      dp[sequence[i]][0] = max(dp[j][1] + 1, dp[sequence[i]][0]);
                    } else {
                      dp[sequence[i]][1] = max(dp[j][0] + 1, dp[sequence[i]][1]);
                    }
                }
            }
            ans = max(ans, max(dp[sequence[i]][1], dp[sequence[i]][0]));
        }
        return ans;
    }
};
