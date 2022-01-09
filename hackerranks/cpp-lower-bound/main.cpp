#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a;
  for (int i{0}; i < n; ++i)
  {
    int ai;
    cin >> ai;
    a.push_back(ai);
  }
  int q;
  cin >> q;
  for (int i{0}; i < q; ++i)
  {
    long query;
    cin >> query;
    long bound{lower_bound(a.begin(), a.end(), query) - a.begin()};
    bool ans{false};
    if (query == a[bound])
    {
      ans = true;
    }
    cout << (ans ? "Yes" : "No") << " " << bound + 1 << endl;
  }

  return 0;
}
