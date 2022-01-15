class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        vector<vector<int>> otherMatrix;
        for (auto row: matrix) {
          for (int i = 1; i <= matrix.size(); i++)
          {
            if (std::find(row.begin(), row.end(), i) == row.end()) {
              return false;
            }
            if (otherMatrix.size() < i) {
                vector<int> column {row[i - 1]};
                otherMatrix.push_back(column);
            } else {
                otherMatrix[i - 1].push_back(row[i - 1]);
            }
          }
        }
        for (auto row: otherMatrix) {
          for (size_t i = 1; i <= matrix.size(); i++) {
            if (std::find(row.begin(), row.end(), i) == row.end()) {
                return false;
            }
          }
        }
        return true;
    }
};
