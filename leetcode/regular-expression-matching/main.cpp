class Solution {
public:
    bool isMatch(string s, string p) {
        int n = (int)s.size();
        int m = (int)p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for (int i{0}; i < m; ++i) {
            for (int j{0}; j <= n; ++j) {
                if (!dp[i][j]) continue;
                if (p[i] == '*') dp[i+1][j] = 1;
                if (i < m-1 && p[i+1] == '*') {
                    for (int k{j}; k < n; ++k) {
                        if (s[k] == p[i] || p[i] == '.') {
                            dp[i+2][k+1] = 1;
                        } else break;
                    }
                    dp[i+2][j] = 1;
                } else if (j < n) {
                    if (s[j] == p[i] || p[i] == '.') {
                        dp[i+1][j+1] = 1;
                    }
                }
            }
        }
        return dp[m][n];
    }
};
