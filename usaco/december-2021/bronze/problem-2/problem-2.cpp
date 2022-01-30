#include <iostream>
#include <ios>
#include <vector>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n{0};
  cin >> n;
  int preferred[n];
  for (int i{0}; i < n; ++i)
  {
    int pi{0};
    cin >> pi;
    preferred[i] = pi;
  }
  for (int i{0}; i < n; ++i)
  {
    int ci{0};
    cin >> ci;
    preferred[i] = preferred[i] - ci;
  }
  int commands{0};
  while (true)
  {
    int nonzero{0};
    while (preferred[nonzero] == 0)
      ++nonzero;
    if (nonzero == n + 1)
      break;
    int currentSignal{preferred[nonzero] > 0 ? 1 : -1};
    int end{nonzero};
    while (end != n && (preferred[end] > 0 ? 1 : (preferred[end] == 0 ? 0 : -1)) == currentSignal)
      ++end;
    --end;
    currentSignal *= -1;
    for (int i{nonzero}; i <= end; i++)
      preferred[i] += currentSignal;
    ++commands;
    bool allZero{true};
    for (int i{0}; i < n; ++i)
    {
      if (preferred[i] != 0)
      {
        allZero = false;
        break;
      }
    }
    if (allZero)
      break;
  }
  std::cout << commands;
}
