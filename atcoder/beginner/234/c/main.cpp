#include <iostream>
#include <cmath>
#include <bitset>

int main()
{
  size_t k;
  std::cin >> k;
  std::string binary = std::bitset<60>(k).to_string();
  std::string ans;
  bool nonzero{false};
  for (size_t i{0}; i < 60; ++i)
  {
    if (nonzero)
    {
      if (binary[i] == '1')
      {
        ans.append("2");
      }
      else
      {
        ans.append("0");
      }
    }
    else if (binary[i] == '1')
    {
      nonzero = true;
      ans.append("2");
    }
  }
  std::cout << ans;
}
