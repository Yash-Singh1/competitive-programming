#include <iostream>

// Doesn't work on all test cases; some edge case? while trying to make this not O(n^2) time

int main()
{
  int nums[9];
  bool numExists[99];
  int sum{0};
  for (size_t i = 0; i < 9; i++)
  {
    std::cin >> nums[i];
    numExists[nums[i]] = true;
    sum += nums[i];
  }
  int existing1;
  int existing2;
  for (size_t i = 0; i < 9; i++)
  {
    if (nums[i] < sum - 100 && numExists[sum - 100 - nums[i]] && sum - 100 - nums[i] != nums[i])
    {
      existing1 = i;
      existing2 = sum - 100 - nums[i];
    }
  }
  for (size_t i = 0; i < 9; i++)
  {
    if (i != existing1 && nums[i] != existing2)
    {
      std::cout << nums[i] << std::endl;
    }
  }
}
