#include <cstdio>
#include <map>

int main()
{
  char correct[3][3];
  char guess[3][3];
  std::map<char, int> exist_map;
  for (int i{0}; i < 3; ++i)
  {
    for (int j{0}; j < 3; ++j)
    {
      scanf(" %c", &correct[i][j]);
      if (exist_map.find(correct[i][j]) == exist_map.end())
      {
        exist_map[correct[i][j]] = 1;
      }
      else
      {
        ++exist_map[correct[i][j]];
      }
    }
  }
  for (int i{0}; i < 3; ++i)
  {
    for (int j{0}; j < 3; ++j)
    {
      scanf(" %c", &guess[i][j]);
    }
  }
  int green{0};
  int yellow{0};
  for (int i{0}; i < 3; ++i)
  {
    for (int j{0}; j < 3; ++j)
    {
      if (correct[i][j] == guess[i][j])
      {
        ++green;
        if (exist_map[guess[i][j]] > 0) --exist_map[guess[i][j]];
      }
      else if (exist_map.find(guess[i][j]) != exist_map.end() && exist_map[guess[i][j]] > 0)
      {
        ++yellow;
        --exist_map[guess[i][j]];
      }
    }
  }
  printf("%d\n%d", green, yellow);
}
