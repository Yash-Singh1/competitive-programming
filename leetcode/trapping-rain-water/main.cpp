class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> mxfront(n), mxback(n);
        mxfront[0] = INT_MIN; mxback[n-1] = INT_MIN;
        for (int i = 1; i < height.size(); ++i) {
            mxfront[i] = max(mxfront[i - 1], height[i - 1]);
        }
        for (int i = height.size() - 2; i >= 0; --i) {
            mxback[i] = max(mxback[i + 1], height[i + 1]);
        }
        int ans = 0;
        for (int i = 1; i < height.size() - 1; ++i) {
            if (mxfront[i] <= height[i] || mxback[i] <= height[i]) continue;
            ans += min(mxfront[i], mxback[i]) - height[i];
        }
        return ans;
    }
};
