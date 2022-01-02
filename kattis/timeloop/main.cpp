#include <iostream>

int main() {
  size_t n;
  std::cin >> n;

  for (size_t i{1}; i <= n; ++i) {
    std::cout << i << " Abracadabra" << std::endl;
  }

  return 0;
}
