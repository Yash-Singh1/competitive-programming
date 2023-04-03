#include <iostream>
#include <ios>
#include <map>
#include <vector>
#include <algorithm>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  std::map<int, int> occur;
  ++n;
  while (--n)
  {
    int x;
    cin >> x;
    ++occur[x];
  }
  int need[m];
  for (int i{0}; i < m; ++i)
  {
    cin >> need[i];
    int change{std::min(occur[i + 1], need[i])};
    occur[i + 1] -= change;
    need[i] -= change;
  }
  std::vector<int> nums;
  for (const auto &[key, value] : occur)
  {
    for (int i{0}; i < value; ++i)
    {
      nums.push_back(key);
    }
  }
  std::sort(nums.begin(), nums.end());
  int offset{0};
  int cost{0};
  for (int i{0}; i < m; ++i)
  {
    for (int j{0}; j < need[i]; ++j)
    {
      int minK{std::abs(nums[offset] - (i + 1))};
      int minKIdx{offset};
      for (int k{offset}; k < nums.size(); ++k)
      {
        if (std::abs(nums[offset] - (i + 1)) < minK)
        {
          minK = nums[k];
          minKIdx = k;
        }
      }
      offset = minKIdx + 1;
      cost += minK;
    }
  }
  std::cout << cost;
}
