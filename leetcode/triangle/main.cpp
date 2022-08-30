class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp {triangle[0][0]};
        for (int i{1}; i < triangle.size(); ++i) {
            vector<int> sub;
            sub.push_back(triangle[i][0] + dp[0]);
            for (int j{0}; j < triangle[i].size() - 1; ++j) {
                sub[j] = min(sub[j], triangle[i][j] + dp[j]);
                sub.push_back(triangle[i][j + 1] + dp[j]);
            }
            dp = sub;
        }
        int mini{INT_MAX - 10};
        for (auto dpp: dp) {
            if (dpp < mini) {
                mini = dpp;
            }
        }
        return mini;
    }
};
