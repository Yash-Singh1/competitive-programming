class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
      int n{(int)nums1.size()};
      if (k == 0) {
        for (int i{0}; i < n; ++i) {
          if (nums1[i] != nums2[i]) return -1;
        }
        return 0;
      }
      long long sm{0};
      long long ops{0};
      for (int i{0}; i < n; ++i) {
        nums1[i] = nums2[i] - nums1[i];
        sm += nums1[i];
        if (nums1[i] % k != 0) {
          return -1LL;
        }
        ops += abs((long long)nums1[i] / k);
      }
      if (sm != 0) {
        return -1LL;
      }
      ops /= 2LL;
      return ops;
    }
};
