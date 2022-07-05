class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int msum{-1};
      int sum {0};
      bool changed{false};
      for (auto num: nums) {
        if (sum < 0) {
          sum = num;
        } else {
          sum += num;
        }
        if (sum > msum || !changed) {
          changed= 1;
          msum = sum;
        }
      }
      return msum;
    }
};
