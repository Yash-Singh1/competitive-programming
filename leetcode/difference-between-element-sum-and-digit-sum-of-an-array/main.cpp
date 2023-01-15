class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
      int sm{0}, dsm{0};
      for (auto &nm: nums) {
        sm += nm;
        while (nm) {
          dsm += nm%10;
          nm /= 10;
        }
      }
      return abs(sm - dsm);
    }
};
