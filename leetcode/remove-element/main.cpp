class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it = nums.begin();
        for (int i{0}; i < nums.size(); ++i) {
            if (nums[i] == val) {
                nums.erase(it);
                --i;
            } else {
                ++it;
            }
        }
        return nums.size();
    }
};
