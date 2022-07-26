// WA, suspect some sort of memory overflow

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1" << endl;
    return 0;
  }
  vector<pair<long double, long double>> a;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a.push_back({x, y});
  }
  int m{2};
  for (int i{0}; i < n; ++i)
  {
    for (int j{0}; j < n; ++j)
    {
      if (i != j)
      {
        int tot{2};
        long double slope{abs((a.at(i).second - a.at(j).second) / (a.at(i).first - a.at(j).first))};
        long double yIntercept{a.at(i).second - (slope * a.at(i).first)};
        for (int k{0}; k < n; ++k)
        {
          if (k != i && k != j)
          {
            if (abs((a.at(k).second - a.at(j).second) / (a.at(k).first - a.at(j).first)) == slope && (a.at(k).second - (slope * a.at(k).first)) == yIntercept)
            {
              ++tot;
            }
          }
        }
        if (tot > m)
        {
          m = tot;
        }
      }
    }
  }
  cout << m;
}
