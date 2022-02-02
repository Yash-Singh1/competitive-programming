// Time complexity too high so it doesn't work

#include <iostream>
#include <ios>
#include <vector>
#include <limits>
#include <algorithm>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t{0};
  cin >> t;
  for (int i{0}; i < t; ++i)
  {
    int n{0};
    cin >> n;
    long long min{-1};
    long long sum{0};
    long long h[n];
    for (int j{0}; j < n; ++j)
    {
      cin >> h[j];
      if (h[j] < min || min == -1)
        min = h[j];
      sum += h[j];
    }
    long long ans{-1};
    for (long long j{min}; j >= 0; --j)
    {
      long long sim[n];
      for (int k{0}; k < n; ++k)
      {
        sim[k] = h[k];
      }
      bool fail{false};
      long long myans{0};
      for (int k{0}; k < n - 1; ++k)
      {
        if (sim[k] < j || sim[k + 1] < sim[k] - j)
        {
          fail = true;
          break;
        }
        sim[k + 1] -= sim[k] - j;
        myans += sim[k] - j;
      }
      if (fail || sim[n - 1] != j)
        continue;
      ans = myans * 2;
      break;
    }
    std::cout << ans << "\n";
  }
}
