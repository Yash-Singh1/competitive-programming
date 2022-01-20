#include <iostream>

int main()
{
  int n, k;
  std::cin >> n >> k;
  int totalMin{(n - k) * -3};
  int totalMax{(n - k) * 3};
  for (int i = 0; i < k; i++)
  {
    int adding;
    std::cin >> adding;
    totalMin += adding;
    totalMax += adding;
  }
  std::cout << static_cast<double>(totalMin) / n << ' ' << static_cast<double>(totalMax) / n;
}
