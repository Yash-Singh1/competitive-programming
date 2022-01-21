#include <cstdio>
#include <set>
#include <cctype>

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    std::set<char> s{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char str[100];
    scanf(" %[^\n]s", &str);
    for (int j = 0; j < 100; j++)
    {
      if (str[j] != '\0')
      {
        auto it = s.find(static_cast<char>(tolower(str[j])));
        if (it != s.end())
        {
          s.erase(it);
        }
      }
      else
      {
        break;
      }
    }
    if (s.size() == 0)
    {
      printf("pangram\n");
    }
    else
    {
      printf("missing ");
      std::set<char>::iterator it = s.begin();
      for (long unsigned k = 0; k < s.size(); k++)
      {
        printf("%c", *it);
        std::advance(it, 1);
      }
      printf("\n");
    }
  }
}
