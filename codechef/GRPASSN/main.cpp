// WA

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  ++t;
  while (--t)
  {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i{2}; i <= n; ++i)
    {
      a[i] = 0;
    }
    for (int i{0}; i < n; ++i)
    {
      int x;
      cin >> x;
      ++a[x];
    }
    bool fail{false};
    for (int i{2}; i <= n; ++i)
    {
      if (!fail)
      {
        if (a[i] != 0 && a[i] != i)
        {
          cout << "NO" << endl;
          fail = true;
        }
      }
    }
    if (!fail)
    {
      cout << "YES" << endl;
    }
  }
}
