#include <iostream>

int main()
{
  size_t n;
  std::cin >> n;
  for (size_t i{0}; i < n; i++)
  {
    int k;
    std::cin >> k;
    int total{1 - k};
    for (int j {0}; j < k; ++j)
    {
      int oj;
      std::cin >> oj;
      total += oj;
    }
    std::cout << total << std::endl;
  }
}
