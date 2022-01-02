#include <iostream>

using std::cin;

int main()
{
  int x, n;
  cin >> x >> n;
  int left{(n + 1) * x};
  for (int i{0}; i < n; i++)
  {
    int newNum {0};
    cin >> newNum;
    left -= newNum;
  }
  std::cout << left;
}
