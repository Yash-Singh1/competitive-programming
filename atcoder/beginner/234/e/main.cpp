#include <iostream>
#include <cctype>
#include <cmath>

int main()
{
  long long x;
  std::cin >> x;
  bool found{false};
  int addition{0};
  while (!found)
  {
    x += addition;
    addition = 1;
    if (x < 101)
    {
      found = true;
    }
    else
    {
      std::string tostring{std::to_string(x)};
      if (tostring[0] - '0' != 9 && tostring.size() < static_cast<short unsigned>((tostring[0] - '0') + 1) && static_cast<short unsigned>(10 - (tostring[0] - '0')) > tostring.size())
      {
        addition = 0;
        x = ((tostring[0] - '0') + 1) * pow(10, tostring.size() - 1);
        continue;
      }
      int difference{(tostring[1] - '0') - (tostring[0] - '0')};
      bool internalFound{true};
      for (size_t i{1}; i < tostring.size() - 1; ++i)
      {
        if ((tostring[i + 1] - '0') - (tostring[i] - '0') != difference)
        {
          internalFound = false;
          break;
        }
      }
      if (internalFound)
      {
        found = true;
      }
    }
  }
  std::cout << x;
}
