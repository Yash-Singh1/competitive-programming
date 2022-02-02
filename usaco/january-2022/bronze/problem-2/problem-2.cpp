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
    int die1[4], die2[4];
    for (int j{0}; j < 4; ++j)
    {
      cin >> die1[j];
    }
    double prob2{0};
    double prob1{0};
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
    bool done{false};
    for (int j{1}; j <= 10; ++j)
    {
      for (int k{j}; k <= 10; ++k)
      {
        for (int l{k}; l <= 10; ++l)
        {
          for (int m{l}; m <= 10; ++m)
          {
            double prob3{0};
            double prob4{0};
            int die3[4]{j, k, l, m};
            for (int j{0}; j < 4; ++j)
            {
              for (int k{0}; k < 4; ++k)
              {
                if (die2[j] > die3[k])
                {
                  prob3 += 0.25;
                }
              }
            }
            for (int j{0}; j < 4; ++j)
            {
              for (int k{0}; k < 4; ++k)
              {
                if (die3[j] > die2[k])
                {
                  prob4 += 0.25;
                }
              }
            }
            if (prob3 > prob4)
            {
              continue;
            }
            double prob5{0};
            double prob6{0};
            for (int j{0}; j < 4; ++j)
            {
              for (int k{0}; k < 4; ++k)
              {
                if (die1[j] > die3[k])
                {
                  prob5 += 0.25;
                }
              }
            }
            for (int j{0}; j < 4; ++j)
            {
              for (int k{0}; k < 4; ++k)
              {
                if (die3[j] > die1[k])
                {
                  prob6 += 0.25;
                }
              }
            }
            if (prob6 < prob5)
            {
              continue;
            }
            std::cout << "yes\n";
            done = true;
            break;
          }
          if (done)
          {
            break;
          }
        }
        if (done)
        {
          break;
        }
      }
      if (done)
      {
        break;
      }
    }
    if (done)
    {
      continue;
    }
    else
    {
      std::cout << "no\n";
    }
  }
}
