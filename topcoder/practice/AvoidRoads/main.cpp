// Didn't test, but y not

class AvoidRoads {
  public:
    long long numWays(int width, int height, vector <string> bad) {
        sort(bad.begin(), bad.end());
        vector<vector<long long>> dp(width + 1, vector<long long>(height + 1));
        dp[0][0] = 1LL;
        for (int i{0}; i <= width; ++i) {
            for (int j{0}; j <= height; ++j) {
                if (i != width) {
                    if (bad.find(to_string(i) + " " + to_string(j) + " " + to_string(i + 1) + " " + to_string(j)) == bad.end()) {
                        dp[i + 1][j] += dp[i][j];
                    }
                }
                if (j != height) {
                    if (bad.find(to_string(i) + " " + to_string(j) + " " + to_string(i) + " " + to_string(j + 1)) == bad.end()) {
                        dp[i][j + 1] += dp[i][j];
                    }
                }
            }
        }
        return dp[width][height];
    }
};
