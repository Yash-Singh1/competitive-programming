#include <iostream>

int main() {
  int n {0};
  std::cin >> n;

  for (int i{0}; i < n; ++i) {
    std::string str;
    std::cin >> str;
    if (i % 2 == 0) {
      std::cout << str << std::endl;
    }
  }
}
