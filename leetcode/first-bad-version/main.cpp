class Solution {
public:
    int firstBadVersion(int n) {
        long long low{1};
        long long high{n};
        long long ans{-1};
        while (low <= high) {
            long long mid{(low + high) / 2};
            if (isBadVersion(mid)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
