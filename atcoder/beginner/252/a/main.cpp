#include <iostream>
#include <ios>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int val;
  cin >> val;
  char c = val;
  std::cout << c;
}
