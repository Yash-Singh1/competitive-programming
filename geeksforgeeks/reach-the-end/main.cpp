// WIP
class Solution {
  public:
    int solve(vector<int>& h) {
        int dp[h.size() + 5];
        for (int i{0}; i< h.size() + 5; ++i) {
            dp[i] = 0;
        }
        for (int i{0}; i < h.size(); ++i) {
            dp[i + 1] = min((dp[i + 1] == 0 ? INT_MAX - 5 : dp[i + 1]), dp[i] + abs(h[i] - h[i + 1]));
            dp[i + 2] = min((dp[i + 2] == 0 ? INT_MAX - 5 : dp[i + 2]), dp[i] + (abs(h.at(i) - (h.size() > i + 2 ? h.at(i + 2) : 0)) * 2));
        }
        return dp[h.size() - 1];
    }
};