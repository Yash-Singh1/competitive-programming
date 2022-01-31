#include <iostream>
#include <ios>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int b1x1{0}, b1y1{0}, b1x2{0}, b1y2{0}, b2x1{0}, b2y1{0}, b2x2{0}, b2y2{0}, tx1{0}, ty1{0}, tx2{0}, ty2{0};
  cin >> b1x1 >> b1y1 >> b1x2 >> b1y2 >> b2x1 >> b2y1 >> b2x2 >> b2y2 >> tx1 >> ty1 >> tx2 >> ty2;
  std::cout << ((b1x2 - b1x1) * (b1y2 - b1y1)) - (std::max((std::min(tx2, b1x2) - std::max(tx1, b1x1)), 0) * std::max((std::min(ty2, b1y2) - std::max(ty1, b1y1)), 0)) + ((b2x2 - b2x1) * (b2y2 - b2y1)) - (std::max((std::min(tx2, b2x2) - std::max(tx1, b2x1)), 0) * std::max((std::min(ty2, b2y2) - std::max(ty1, b2y1)), 0));
}
