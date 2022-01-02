#include <iostream>

int main()
{
  int n{0};
  std::cin >> n;
  int m{0};
  std::cin >> m;

  bool houses[n];
  for (int i{1}; i < n; ++i)
  {
    houses[i] = false;
  }
  houses[0] = true;

  size_t connections[m][2];
  for (int i{0}; i < m; ++i)
  {
    std::cin >> connections[i][0] >> connections[i][1];
  }

  bool changed{false};
  do
  {
    changed = false;
    for (int i{0}; i < m; ++i)
    {
      if (houses[connections[i][0] - 1])
      {
        if (houses[connections[i][1] - 1]) {
          continue;
        }
        houses[connections[i][1] - 1] = true;
        changed = true;
      }
      else if (houses[connections[i][1] - 1])
      {
        houses[connections[i][0] - 1] = true;
        changed = true;
      }
    }
  } while (changed);

  bool printed {false};
  for (int i{1}; i < n; ++i)
  {
    if (!houses[i]) {
      printed = true;
      std::cout << i + 1 << std::endl;
    }
  }

  if (!printed) {
    std::cout << "Connected" << std::endl;
  }
}
