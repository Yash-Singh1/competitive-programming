// LOL, This doesn't work it was a failed attempt

#include <iostream>
#include <vector>

using std::vector;

int main()
{
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<vector<int>> edges;
  for (int i = 0; i < m; i++)
  {
    vector<int> abc;
    int a, b, c;
    scanf(" %d %d %d", &a, &b, &c);
    abc.push_back(a);
    abc.push_back(b);
    abc.push_back(c);
    edges.push_back(abc);
  }
  for (int i = 0; i < q; i++)
  {
    int u, v, w;
    scanf(" %d %d %d", &u, &v, &w);
    bool found{false};
    for (auto edge : edges)
    {
      if (edge[0] == u && edge[1] == v && edge[2] < w)
      {
        found = true;
        break;
      }
    }
    if (found)
    {
      printf("No\n");
    }
    else
    {
      printf("Yes\n");
    }
  }
}
