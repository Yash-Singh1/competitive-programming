#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main()
{
  std::cout << std::setprecision (17);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> points;
  double maxLength{0};
  for (int i{0}; i < n; ++i)
  {
    int a, b;
    std::vector<int> point;
    std::cin >> a >> b;
    point.push_back(a);
    point.push_back(b);
    points.push_back(point);
  }
  for (int i{0}; i < n; ++i)
  {
    for (int j{i + 1}; j < n; ++j)
    {
      if (i != j)
      {
        double length{sqrt(pow(static_cast<double>(points[j][1]) - points[i][1], 2) + pow(static_cast<double>(points[j][0]) - points[i][0], 2))};
        if (length > maxLength) {
          maxLength = length;
        }
      }
    }
  }
  std::cout << maxLength;
}
