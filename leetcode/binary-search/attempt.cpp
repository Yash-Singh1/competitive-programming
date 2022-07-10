// TLE

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int deep{1};
        unsigned long idx{(nums.size() - 1) / 2};
        bool found {false};
        while (!found && idx > 0 && idx < nums.size() - 1) {
            if (nums[idx] > target) {
                //if (idx != 0 && nums[idx - 1] < target) return -1;
                idx -= (nums.size() - 1) / pow(2, deep);
            } else if (nums[idx] < target) {
                //if (idx != nums.size() - 1 && nums[idx + 1] > target) return -1;
                idx += (nums.size() - 1) / pow(2, deep);
            } else {
                found = true;
            }
            ++deep;
        }
        if (found || nums[idx] == target)  return idx;
        else if (idx < nums.size() - 1 && nums[idx + 1] == target) return idx + 1;
        return -1;
    }
};
