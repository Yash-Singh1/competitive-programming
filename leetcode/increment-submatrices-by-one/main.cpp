class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
      vector<vector<int>> p(n, vector<int>(n));
      for (auto &q: queries) {
        ++p[q[0]][q[1]];
        if (q[3] + 1 != n) --p[q[0]][q[3] + 1];
        if (q[2] + 1 != n) --p[q[2] + 1][q[1]];
        if (q[2] + 1 != n && q[3] + 1 != n) ++p[q[2] + 1][q[3] + 1];
      }
      for (int i{0}; i < n; ++i) {
        for (int j{0}; j < n; ++j) {
          if (i != 0) p[i][j] += p[i - 1][j];
          if (j != 0) p[i][j] += p[i][j - 1];
          if (i != 0 && j != 0) {
            p[i][j] -= p[i - 1][j - 1];
          }
        }
      }
      return p;
    }
};
