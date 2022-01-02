#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int main()
{
  string input;
  std::cin >> input;

  vector<vector<string>> parts;
  bool newOne{true};
  bool newInner{false};
  for (auto part : input)
  {
    if (part == ';')
    {
      newOne = true;
    }
    else if (part == '-')
    {
      newInner = true;
    }
    else
    {
      if (newInner)
      {
        parts.back().push_back(string{part});
        newInner = false;
      }
      else if (newOne)
      {
        parts.push_back(vector<string>{string{part}});
        newOne = false;
      }
      else
      {
        parts.back().back().append(string{part});
      }
    }
  }

  int problems{0};
  for (auto part : parts)
  {
    if (part.size() == 1)
    {
      problems++;
    }
    else
    {
      problems += std::stoi(part[1]) - std::stoi(part[0]) + 1;
    }
  }

  std::cout << problems << std::endl;
}
