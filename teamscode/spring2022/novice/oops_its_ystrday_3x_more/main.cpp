#include <iostream>
#include <ios>
#include <set>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  ++t;
  while (--t)
  {
    int n;
    char next;
    cin >> n;
    int x{0}, y{0};
    int minx{0}, maxx{0}, miny{0}, maxy{0};
    ++n;
    while (--n)
    {
      cin >> next;
      if (next == 'L' || next == 'R')
      {
        if (next == 'L')
        {
          x -= 1;
        }
        else
        {
          x += 1;
        }
        if (x < minx)
        {
          minx = x;
        }
        if (x > maxx)
        {
          maxx = x;
        }
      }
      else
      {
        if (next == 'U')
        {
          y += 1;
        }
        else
        {
          y -= 1;
        }
        if (y < miny)
        {
          miny = y;
        }
        if (y > maxy)
        {
          maxy = y;
        }
      }
    }
    std::cout << (maxx - minx + 1) * (maxy - miny + 1) << std::endl;
  }
}
