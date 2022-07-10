class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low{0};
        int high{static_cast<int>(nums.size()) - 1};
        int rotPoint{0};
        while (low <= high) {
            int mid{(low + high) / 2};
            if (mid + 1 != static_cast<int>(nums.size()) && nums[mid + 1] < nums[mid]) {
                rotPoint = mid;
                break;
            } else if (mid != 0 && nums[mid - 1] > nums[mid]) {
                rotPoint = mid - 1;
                break;
            } else if (nums[low] > nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low = 0;
        high = rotPoint;
        while (low <= high) {
            int mid{(low + high) / 2};
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low = min(rotPoint + 1, static_cast<int>(nums.size()) - 1);
        high = nums.size() - 1;
        cout << low << " " << high;
        while (low <= high) {
            int mid{(low + high) / 2};
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
