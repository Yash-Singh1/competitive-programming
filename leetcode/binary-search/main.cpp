class Solution {
public:
    int search(vector<int>& nums, int target) {
        long long low{0};
        long long high{static_cast<long long>(nums.size() - 1)};
        while (low <= high) {
            long long mid{(low + high) / 2};
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
