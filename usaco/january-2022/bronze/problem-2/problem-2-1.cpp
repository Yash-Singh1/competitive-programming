#include <iostream>
#include <ios>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t{0};
  cin >> t;
  for (int i{0}; i < t; ++i)
  {
    bool no {true};
    int die1[4], die2[4];
    for (int j{0}; j < 4; ++j)
    {
      cin >> die1[j];
    }
    double prob2 {0};
    double prob1 {0};
    for (int j{0}; j < 4; ++j)
    {
      cin >> die2[j];
      for (int k{0}; k < 4; ++k)
      {
        if (die2[j] > die1[k])
        {
          prob2 += 0.25;
        }
      }
    }
    for (int j{0}; j < 4; ++j)
    {
      for (int k{0}; k < 4; ++k)
      {
        if (die1[j] > die2[k])
        {
          prob1 += 0.25;
        }
      }
    }
    for (int j{0}; j < 4; ++j) {
      if (die1[j] != die1[0] || die2[j] != die2[0]) {
        no = false;
        break;
      }
    }
    if (no || prob1 == 4 || prob2 == 4) {
      std::cout << "no\n";
    } else {
      std::cout << "yes\n";
    }
  }
}
