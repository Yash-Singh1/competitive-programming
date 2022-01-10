#include <iostream>
#include <cmath>

int main() {
  double_t h, v;
  std::cin >> h >> v;
  if (v >= 0 && v <= 180) {
    std::cout << "safe";
  } else {
    std::cout << static_cast<int>(h / cos((v - 270) / 180 * M_PI));
  }
}
