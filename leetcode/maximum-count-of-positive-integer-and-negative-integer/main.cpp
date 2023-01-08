class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p{0}, n{0};
      for (auto &num: nums) {
        if (num < 0) ++n;
        else if (num > 0) ++p;
      }
      return max(p, n);
    }
};
