#include <bits/stdc++.h>

using namespace std;

int lcs(string a, string b)
{
  int arr[a.size() + 1][b.size() + 1];
  for (int i{0}; i <= a.size(); ++i)
  {
    for (int j{0}; j <= b.size(); ++j)
    {
      if (i == 0 || j == 0)
      {
        arr[i][j] = 0;
      }
      else if (a[i - 1] == b[j - 1])
      {
        arr[i][j] = arr[i - 1][j - 1] + 1;
      }
      else
      {
        arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
      }
      // cout << arr[i][j] << " ";
    }
    // cout << endl;
  }
  return arr[a.size()][b.size()];
}
