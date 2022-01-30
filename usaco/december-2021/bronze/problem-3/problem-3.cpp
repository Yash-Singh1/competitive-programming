// Has some flaws when attempting to not brute force K = 3 to get less than O(n^3)

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
    int n{0}, k{0};
    cin >> n >> k;
    char grid[n][n];
    for (int m{0}; m < n; ++m)
    {
      for (int j{0}; j < n; ++j)
      {
        cin >> grid[m][j];
      }
    }
    int pos{2};
    bool up{true};
    bool down{true};
    for (int m{0}; m < n; m++)
    {
      if (grid[0][m] == 'H' || grid[m][n - 1] == 'H')
      {
        up = false;
      }
      if (grid[m][0] == 'H' || grid[n - 1][m] == 'H')
      {
        down = false;
      }
    }
    if (!up)
    {
      pos--;
    }
    if (!down)
    {
      pos--;
    }
    if (k >= 2)
    {
      pos += 2 * n - 4;
      for (int j{1}; j < n - 1; ++j)
      {
        bool validD{true};
        bool validR{true};
        for (int k{1}; k <= j; ++k)
        {
          if (grid[k][0] == 'H')
          {
            validD = false;
          }
          if (grid[0][k] == 'H')
          {
            validR = false;
          }
        }
        for (int k{j + 1}; k <= n - 1; ++k)
        {
          if (grid[k][n - 1] == 'H')
          {
            validD = false;
          }
          if (grid[n - 1][k] == 'H')
          {
            validR = false;
          }
        }
        for (int k{0}; k < n; ++k)
        {
          if (grid[j][k] == 'H')
          {
            validD = false;
          }
          if (grid[k][j] == 'H')
          {
            validR = false;
          }
        }
        if (!validD)
        {
          pos--;
        }
        if (!validR)
        {
          pos--;
        }
      }
      if (k == 3)
      {
        for (int j{1}; j < n - 1; j++)
        {
          bool possibleD{true};
          bool possibleR{true};
          for (int k{1}; k <= j; k++)
          {
            if (grid[k][0] == 'H')
            {
              possibleD = false;
            }
            if (grid[0][k] == 'H')
            {
              possibleR = false;
            }
          }
          if (!possibleD && !possibleR)
          {
            break;
          }
          if (possibleD)
          {
            int maxIn{0};
            for (int k{1}; k < n - 1; k++)
            {
              if (grid[j][k] == 'H')
              {
                break;
              }
              ++maxIn;
            }
            for (int k{1}; k <= maxIn; k++)
            {
              bool pathPos{true};
              for (int l{j}; l < n; l++)
              {
                if (grid[l][maxIn] == 'H')
                {
                  pathPos = false;
                  break;
                }
              }
              if (!pathPos)
              {
                break;
              }
              for (int l{maxIn + 1}; l < n - 1; l++)
              {
                if (grid[n - 1][l] == 'H')
                {
                  pathPos = false;
                  break;
                }
              }
              if (!pathPos)
              {
                break;
              }
              ++pos;
            }
          }
          if (possibleR)
          {
            int maxIn{0};
            for (int k{1}; k < n - 1; k++)
            {
              if (grid[k][j] == 'H')
              {
                break;
              }
              ++maxIn;
            }
            for (int k{1}; k <= maxIn; ++k)
            {
              bool pathPos{true};
              for (int l{j}; l < n; ++l)
              {
                if (grid[k][l] == 'H')
                {
                  pathPos = false;
                  break;
                }
              }
              if (!pathPos)
              {
                break;
              }
              for (int l{k + 1}; l < n - 1; ++l)
              {
                if (grid[l][n - 1] == 'H')
                {
                  pathPos = false;
                  break;
                }
              }
              if (!pathPos)
              {
                break;
              }
              ++pos;
            }
          }
        }
      }
    }
    std::cout << pos << '\n';
  }
}
