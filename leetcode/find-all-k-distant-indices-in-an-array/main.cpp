class Solution
{
public:
  vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
  {
    vector<int> kDistantIndices;
    for (int i{0}; i < nums.size(); ++i)
    {
      for (int j{std::max(i - k, 0)}; j <= i + k && j < nums.size(); ++j)
      {
        if (nums[j] == key)
        {
          kDistantIndices.push_back(i);
          break;
        }
      }
    }
    return kDistantIndices;
  }
};
