#include <iostream>
#include <ios>
#include <set>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ++n;
  while (--n)
  {
    int a;
    cin >> a;
    std::cout << a << ' ' << a + 1 << ' ' << a + a + 1 << ' ' << a + a + 1 << std::endl;
  }
}
