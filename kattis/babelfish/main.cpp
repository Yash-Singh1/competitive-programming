#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  std::string line;
  map<string, string> m;

  while (std::getline(std::cin, line) && !line.empty())
  {
    m[line.substr(line.find(' ') + 1, line.size() - line.find(' '))] = line.substr(0, line.find(' '));
  }

  while (getline(cin, line)) {
    if (m.find(line) != m.end()) {
      cout << m[line] << "\n";
    } else {
      cout << "eh" << "\n";
    }
  }

  return 0;
}
