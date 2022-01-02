#include <iostream>
#include <vector>
#include <iomanip>

float get_average(int numbers[], size_t length)
{
  int total{0};
  for (size_t i = 0; i < length; i++)
  {
    total += numbers[i];
  }
  return static_cast<float>(total) / length;
}

int main()
{
  std::cout << std::fixed << std::setprecision(3);
  size_t dataSets;
  std::cin >> dataSets;

  for (size_t i{0}; i < dataSets; ++i)
  {
    size_t amount;
    std::cin >> amount;
    int scores[amount];
    for (size_t j{0}; j < amount; ++j)
    {
      std::cin >> scores[j];
    }
    int total {0};
    float average {get_average(scores, amount)};
    for (size_t j{0}; j < amount; ++j)
    {
      if (scores[j] > average) {
        ++total;
      }
    }
    std::cout << static_cast<float>(total) / amount * 100 << "%" << std::endl;
  }
}
