#include <iostream>
#include <ios>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int a[n];
  int b[n];
  for (int i{0}; i < n; ++i)
  {
    cin >> a[i];
  }
  for (int i{0}; i < n; ++i)
  {
    cin >> b[i];
  }
  int match[n + 1][n + 1];
  for (int i{0}; i < n + 1; ++i)
  {
    for (int j{0}; j < n + 1; ++j)
    {
      if (i == 0 || j == 0)
      {
        match[i][j] = 0;
      }
      else if (a[i - 1] == b[j - 1])
      {
        match[i][j] = match[i - 1][j - 1] + 1;
      }
      else
      {
        match[i][j] = std::max(match[i - 1][j], match[i][j - 1]);
      }
    }
  }
  std::cout << n - match[n][n];
}
