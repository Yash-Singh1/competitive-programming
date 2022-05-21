#include <iostream>
#include <ios>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  std::cout << (n % 2 == 0 && n > 1 ? "YES" : "NO");
}
