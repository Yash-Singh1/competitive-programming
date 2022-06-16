#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int x;
  double y;
  cin >> x >> y;
  if (x % 5 == 0 && y >= (x + 0.5))
  {
    y -= x;
    y -= 0.5;
  }
  std::cout << std::fixed << std::setprecision(2) << y;
}
