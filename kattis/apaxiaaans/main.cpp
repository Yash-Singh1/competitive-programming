#include <iostream>

int main() {
  std::string name;
  std::cin >> name;

  char lastChar {'A'};
  for (auto character: name) {
    if (lastChar != character) {
      lastChar = character;
      std::cout << character;
    }
  }
}
