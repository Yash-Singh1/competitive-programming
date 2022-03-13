#include <iostream>
#include <ios>

using std::cin;

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
    for (int j{sum == 0 ? 0 : 1}; j <= sum; ++j)
    {
      if (j >= max && (j == 0 || sum % j == 0) && (j == 0 || sum / j <= n)) {
        std::cout << n - (j == 0 ? 0 : sum / j) << std::endl;
        break;
      }
    }
  }
}
