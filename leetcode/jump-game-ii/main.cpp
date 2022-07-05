class Solution {
public:
    int jump(vector<int>& nums) {
      vector<int> a(nums.size(), -1);
      a[0] = 0;
      for (int i{0}; i < nums.size(); ++i) {
        for (int j{i + 1}; j <= i + nums[i] && j < nums.size(); ++j) {
          if (a[j] == -1 || a[j] > a[i] + 1) {
            a[j] = a[i] + 1;
          }
        }
      }
      return a[nums.size() - 1];
    }
};
