#include <cstdio>
#include <vector>

int main()
{
  int n, q;
  scanf("%d %d", &n, &q);
  std::vector<int> a;
  for (int i = 0; i < n; ++i)
  {
    int ai;
    scanf(" %d", &ai);
    a.push_back(ai);
  }
  for (int i = 0; i < q; ++i)
  {
    int x, k;
    scanf(" %d %d", &x, &k);
    int occur{0};
    int ind{-1};
    size_t j{0};
    for (auto ai : a)
    {
      if (ai == x && ++occur == k)
      {
        ind = j + 1;
        break;
      }
      ++j;
    }
    printf("%d\n", ind);
  }
}
