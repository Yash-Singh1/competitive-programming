#include <iostream>
#include <string>

int main() {
  unsigned long long l{0};
  std::cin >> l;

  for (int i {1}; i < l; ++i) {
    if (static_cast<unsigned long long>(std::to_string(i).size() * i) == l) {
      std::cout << i << std::endl;
      break;
    }
  }
}
