#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i{0}; i < nums.size(); ++i) {
          if (nums[i] == -101) {
            if (i + 1 == nums.size() || nums[i + 1] == -101) break;
            nums[i] = nums[i + 1];
            nums[i + 1] = -101;
          }
          if (i != 0 && nums[i - 1] == nums[i]) {
            nums[i] = i == nums.size() - 1 ? -101 : nums[i + 1];
            if (i != nums.size() - 1) {
              nums[i + 1] = -101;
            }
            --i;
          }
        }
      int k{0};
      for (auto num: nums) {
        if (num == -101) {
          break;
        }
        ++k;
      }
      return k;
    }
};
