class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
      int j{0};
      for (auto &el: nums1) {
        while (j < (int)nums2.size() && nums2[j] < el) {
          ++j;
        }
        if (j < (int)nums2.size() && nums2[j] == el) return el;
      }
      return -1;
    }
};
