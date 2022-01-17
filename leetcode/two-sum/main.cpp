/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <vector>
#include <map>
#include <algorithm>
using std::map;
using std::vector;

// @lc code=start

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        map<int, int> m2;
        for (size_t i = 0; i < nums.size(); i++)
        {
            m.insert(std::make_pair(nums[i], i));
            if (m[nums[i]] != i) {
                m2.insert(std::make_pair(nums[i], i));
            }
        }
        std::sort(nums.begin(), nums.end());
        for (auto num: nums) {
            if (m.find(target - num) != m.end()) {
                return vector<int>{m[num], num == target - num ? m2[num] : m[target - num]};
            }
        }
        return vector<int>{0, 1};
    }
};
// @lc code=end

