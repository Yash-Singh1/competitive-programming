class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        if (nums.size() > 2) {
          unsigned long max{nums.size() % 2 == 0 ? nums.size() + 1 : nums.size()};  
          for (unsigned long i{1}; i < max; i += 2) {
            int min {-1};
            int minIndex {-1};
            for (unsigned long j{i}; j < max; j += 2) {
              if (min == -1 || nums[j] > min) {
                min = nums[j];
                minIndex = j;
              }
            }
            nums[minIndex] = nums[i];
            nums[i] = min;
          }
        }
      if (nums.size() > 0) {
          unsigned long max{nums.size() % 2 == 0 ? nums.size() : nums.size() + 1};  
          for (unsigned long i{0}; i < max; i += 2) {
            int min {-1};
            int minIndex {-1};
            for (unsigned long j{i}; j < max; j += 2) {
              if (min == -1 || nums[j] < min) {
                min = nums[j];
                minIndex = j;
              }
            }
            nums[minIndex] = nums[i];
            nums[i] = min;
          }
    }
      return nums;
    }
};
