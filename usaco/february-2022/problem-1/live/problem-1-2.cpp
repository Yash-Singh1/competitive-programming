#include <iostream>
#include <ios>

using std::cin;

bool allIdentical(int a[], int n)
{
  for (int i{1}; i < n; ++i)
  {
    if (a[i] != a[0] && a[i] != -1)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i{0}; i < t; ++i)
  {
    int n;
    cin >> n;
    int a[n];
    int sum{0};
    int max{0};
    for (int j{0}; j < n; ++j)
    {
      cin >> a[j];
      if (a[j] > max)
      {
        max = a[j];
      }
      sum += a[j];
    }
    int pushes{0};
    bool notmatch{true};
    bool ultinotmatch{false};
    while (!allIdentical(a, n))
    {
      notmatch = true;
      for (int j{0}; j < n - 1; ++j)
      {
        if ((ultinotmatch || a[j] != max) && a[j] != -1 && a[j + 1] != -1)
        {
          a[j] += a[j + 1];
          if (a[j] > max)
          {
            max = a[j];
          }
          a[j + 1] = -1;
          for (int k{j + 2}; k < n; ++k)
          {
            int swp{a[k - 1]};
            a[k - 1] = a[k];
            a[k] = swp;
          }
          ++pushes;
          notmatch = false;
          break;
        }
      }
      if (ultinotmatch)
        ultinotmatch = false;
      if (notmatch)
      {
        ultinotmatch = true;
        notmatch = false;
      }
    }
    std::cout << pushes << std::endl;
  }
}
