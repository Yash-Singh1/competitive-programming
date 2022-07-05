class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
      ans.push_back({1});
      if (numRows > 1) {
        ans.push_back({1, 1});
      } else {
        return ans;
      }
      numRows -= 2;
      vector<int> prev;
      prev = ans[ans.size() - 1];
      while (numRows > 0) {
        vector<int> next;
        next.push_back(1);
        for (int i{0}; i < prev.size() - 1; ++i) {
          next.push_back(prev[i] + prev[i + 1]);
        }
        next.push_back(1);
        ans.push_back(next);
        prev = next;
        --numRows;
      }
      return ans;
    }
};
