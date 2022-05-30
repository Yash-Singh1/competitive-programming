class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> p;
        p.push_back(nums[0]);
        for (int i{1}; i < nums.size(); ++i) {
            p.push_back(p[i - 1] + nums[i]);
        }
        int ways{0};
        for (int i{0}; i < nums.size() - 1; ++i) {
            if (p[i] >= p[nums.size() - 1] - p[i]) {
                ++ways;
            }
        }
        return ways;
    }
};
