#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int n{0}, q{0};
  cin >> n >> q;
  vector<int> a[n];
  for (int i{0}; i < n; ++i)
  {
    int k{0};
    cin >> k;
    for (int j{0}; j < k; ++j)
    {
      int ki{0};
      cin >> ki;
      a[i].push_back(ki);
    }
  }
  for (int s{0}; s < q; ++s)
  {
    int i{0}, j{0};
    cin >> i >> j;
    cout << a[i][j] << endl;
  }

  return 0;
}
