#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, l;
  cin >> n >> l;
  std::vector<int> a;
  for (int i{0}; i < n; ++i)
  {
    int x;
    cin >> x;
    a.push_back(x);
  }
  std::sort(a.begin(), a.end(), std::greater<int>());
  std::vector<int> cited;
  for (int i{0}; i < l; ++i)
  {
    int lookingNum{-1};
    int lookingNumIndex{-1};
    for (int h{n}; h >= 1; --h)
    {
      if (a[h - 1] >= h)
      {
        lookingNum = a[h - 1];
        lookingNumIndex = h;
        break;
      }
    }
    if (lookingNum != -1)
    {
      bool found{false};
      for (int j{lookingNumIndex}; j < n; ++j)
      {
        if (a[j] < lookingNum && std::find(cited.begin(), cited.end(), j) == cited.end())
        {
          cited.push_back(j);
          ++a[j];
          found = true;
          break;
        }
      }
      if (!found)
      {
        for (int j{0}; j < n; ++j)
        {
          if (a[j] == lookingNum && std::find(a.begin(), a.end(), j) == a.end())
          {
            cited.push_back(j);
            ++a[j];
            break;
          }
        }
      }
    }
    else
    {
      if (n > 0)
        a[0] = 1;
      cited.push_back(0);
    }
  }
  for (int h{n}; h >= 1; --h)
  {
    if (a[h - 1] >= h)
    {
      std::cout << h;
      return 0;
    }
  }
  std::cout << 0;
}
