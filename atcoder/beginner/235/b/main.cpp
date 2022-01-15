#include <iostream>

int main()
{
  int prev{-1};
  int n;
  std::cin >> n;
  for (size_t i = 0; i < n; ++i)
  {
    int h;
    std::cin >> h;
    if (prev >= h) {
      std::cout << prev;
      return 0;
    } else {
      prev = h;
    }
  }
  std::cout << prev;
}
