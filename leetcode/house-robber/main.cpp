class Solution {
public:
    int rob(vector<int>& nums) {
        int a[nums.size()];
        for (int i{0}; i < nums.size(); ++i) {
            a[i] = 0;
        }
        for (int i{0}; i < nums.size(); ++i) {
            if (i + 2 < nums.size())
            a[i + 2] = max(nums[i] + a[i], a[i + 2]);
            if (i + 3 < nums.size())
            a[i + 3] = max(a[i + 3], nums[i] + a[i]);
        }
        for (int i{0}; i < nums.size(); ++i) {
            cout << a[i] <<" ";
        }
        return max(a[nums.size() - 1] + nums[nums.size() - 1], nums.size() > 1 ? (a[nums.size() - 2] + nums[nums.size() - 2]) : 0);
    }
};
