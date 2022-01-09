#include <iostream>
#include <set>

using namespace std;

int main()
{
  set<int> s;
  int q;
  cin >> q;
  for (int i{0}; i < q; ++i)
  {
    int y, x;
    cin >> y >> x;
    switch (y)
    {
    case 1:
      s.insert(x);
      break;
    case 2:
      s.erase(x);
      break;
    case 3:
      if (s.find(x) == s.end())
      {
        cout << "No" << endl;
      }
      else
      {
        cout << "Yes" << endl;
      }
      break;
    }
  }
  return 0;
}
