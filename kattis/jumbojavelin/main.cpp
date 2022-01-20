#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int sum {1 - n};
  for (int i {0}; i < n; i++)
  {
    int next;
    std::cin >> next;
    sum += next;
  }
  std::cout << sum;
}
