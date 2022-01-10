#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a;
  for (int i{0}; i < n; ++i)
  {
    int ni;
    cin >> ni;
    a.push_back(ni);
  }
  int rmEl, rmEl1, rmEl2;
  cin >> rmEl >> rmEl1 >> rmEl2;
  a.erase(a.begin() + rmEl - 1);
  a.erase(a.begin() + rmEl1 - 1, a.begin() + rmEl2 - 1);

  cout << a.size() << endl;
  for (auto i : a)
  {
    cout << i << " ";
  }

  return 0;
}
