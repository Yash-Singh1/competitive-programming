class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool a[nums.size()];
      for (int i{0}; i < nums.size(); ++i) {
        a[i] = false;
      }
      a[0] = true;
      int maxi{0};
      for (int i{0}; i < nums.size(); ++i) {
        if (maxi >= i && nums[i] + i > maxi) {
          maxi = nums[i] + i;
        } else if (maxi < i) {
          return false;
        }
      }
      return maxi >= nums.size() - 1;
    }
};
