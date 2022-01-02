#include <iostream>

int main() {
  std::string first;
  std::string second;

  std::cin >> first >> second;

  if (first.size() >= second.size()) {
    std::cout << "go" << std::endl;
  } else {
    std::cout << "no" << std::endl;
  }
}
