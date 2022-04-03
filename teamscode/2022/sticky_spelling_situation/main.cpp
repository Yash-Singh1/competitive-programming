#include <iostream>
#include <ios>
#include <map>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  std::string str1, str2;
  cin >> str1 >> str2;
  std::map<char, int> first;
  int diff{0};
  for (char c : str1)
    ++first[c];
  for (char c : str2)
  {
    if (first[c] > 0)
      --first[c];
    else
      ++diff;
  }
  std::cout << diff;
}
