#include <iostream>
#include <ios>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int a{0}, b{0}, c{0}, d{0};
  cin >> a >> b >> c >> d;
  std::cout << (b - a) + (d - c) - std::max(std::min(b, d) - std::max(a, c), 0);
}
