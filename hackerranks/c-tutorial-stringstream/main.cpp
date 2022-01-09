#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
  vector<int> ans;
  stringstream ss(str);
  char drop;
  while (!ss.eof())
  {
    int next;
    ss >> next;
    ans.push_back(next);
    ss >> drop;
  }
  return ans;
}

int main()
{
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for (int i = 0; i < integers.size(); i++)
  {
    cout << integers[i] << "\n";
  }

  return 0;
}
