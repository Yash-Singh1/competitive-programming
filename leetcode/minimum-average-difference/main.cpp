class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long num[(int)nums.size()];
        for (int i{0}; i< (int)nums.size(); ++i) num[i] = nums[i];
        for (int i{1}; i < (int)nums.size(); ++i) {
            num[i] += num[i - 1];
        }
        int mn{INT_MAX}, mni{-1};
        for (long long i{0}; i < (int)nums.size(); ++i) {
            long long df{abs((num[i] / (i + 1LL)) - ((num[(long long)nums.size() - 1LL] - num[i]) / ((i == (long long)nums.size() - 1LL) ? 1LL : ((long long)nums.size() - (i + 1LL)))))};
            if (df < mn) {
                mn = df;
                mni = i;
            }
        }
        return mni;
    }
};
