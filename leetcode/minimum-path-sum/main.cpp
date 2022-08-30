class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp;
        for (int i{0}; i < grid.size(); ++i) {
            vector<int> sub;
            for (int j{0}; j < grid[0].size(); ++j) {
                int currentP{INT_MAX - 10};
                if (j > 0) {
                    currentP = min(currentP, sub[j - 1] + grid[i][j]);
                }
                if (i > 0) {
                    currentP = min(currentP, dp[i - 1][j] + grid[i][j]);
                }
                if (i == 0 && j == 0) {
                    currentP = grid[i][j];
                }
                sub.push_back(currentP);
            }
            dp.push_back(sub);
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
