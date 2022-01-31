#include <iostream>
#include <ios>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int b1x1{0}, b1y1{0}, b1x2{0}, b1y2{0}, b2x1{0}, b2y1{0}, b2x2{0}, b2y2{0};
  cin >> b1x1 >> b1y1 >> b1x2 >> b1y2 >> b2x1 >> b2y1 >> b2x2 >> b2y2;
  int tarpX1{b1x1}, tarpY1{b1y1}, tarpX2{b1x2}, tarpY2{b1y2};
  if (b2y1 <= b1y1 && b2y2 >= b1y2) {
    // Covers one or more of the sides
    tarpX1 = std::max(b1x1, b2x1);
    tarpX2 = std::min(b1x2, b2x2);
  }
  if (b2x1 <= b1x1 && b2x2 >= b1x2) {
    // Covers the top or the bottom
    tarpY1 = std::max(b1y1, b2y1);
    tarpY2 = std::min(b1y2, b2y2);
  }
  std::cout << (tarpX2 - tarpX1) * (tarpY2 - tarpY1);
}
