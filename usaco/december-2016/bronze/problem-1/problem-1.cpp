#include <iostream>
#include <ios>
#include <cmath>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int b1x1{0}, b1y1{0}, b1x2{0}, b1y2{0}, b2x1{0}, b2y1{0}, b2x2{0}, b2y2{0};
  cin >> b1x1 >> b1y1 >> b1x2 >> b1y2 >> b2x1 >> b2y1 >> b2x2 >> b2y2;
  std::cout << pow(std::max(std::max(b1x2, b2x2) - std::min(b1x1, b2x1),
                        std::max(b1y2, b2y2) - std::min(b1y1, b2y1)), 2);
}
