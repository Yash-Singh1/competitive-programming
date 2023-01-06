class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n{(int)nums.size()};
        multiset<int> cur;
        for (int i{0}; i < k; ++i) {
            cur.insert(nums[i]);
        }
        vector<int> ans(n - k + 1);
        for (int l{0}; l <= n - k; ++l) {
            ans[l] = *cur.rbegin();
            if (l != n - k) cur.insert(nums[l + k]);
            cur.erase(cur.find(nums[l]));
        }
        return ans;
    }
};
