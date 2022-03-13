class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
      int grid[n][n];
      for (int i{0}; i < n; ++i) {
        for (int j{0}; j < n; ++j) {
          grid[i][j] = 0;
        }
      }
      for (int k{0}; k < artifacts.size(); ++k) {
        for (int i{artifacts[k][0]}; i <= artifacts[k][2]; ++i) {
          for (int j{artifacts[k][1]}; j <= artifacts[k][3]; ++j) {
            grid[i][j] = k + 1;
          }
        }
      }
      for (int i{0}; i < dig.size(); ++i) {
        grid[dig[i][0]][dig[i][1]] = 0;
      }
      set<int> missed;
      for (int i{0}; i < n; ++i) {
        for (int j{0}; j < n; ++j) {
          missed.insert(grid[i][j]);
        }
      }
      missed.insert(0);
    for (auto itr = missed.begin(); itr != missed.end(); itr++) {
        cout << *itr << " ";
    }
      return artifacts.size() - (missed.size() - 1);
    }
};
