/*
ID: saiansh1
LANG: C++
TASK: namenum
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> valid_words(string s)
{
  vector<string> ans;

  if (s.size() == 0)
  {
    string a = "";
    ans.push_back(a);
    return ans;
  }

  char first{65 + 3 * (s[0] - 50)};
  s = s.substr(1, s.size() - 1);

  vector<string> validGiven = valid_words(s);
  for (auto validWord : validGiven)
  {
    for (int i = first; i < first + (first == 82 ? 3 : 4); i++)
    {
      char x = i;
      if (x == 'Q') continue;
      validWord = x + validWord;
      ans.push_back(validWord);
      validWord = validWord.substr(1, validWord.size() - 1);
    }
  }
  validGiven.clear();

  return ans;
}

int main()
{
  ofstream fout("namenum.out");
  ifstream fin("namenum.in");
  ifstream dict("dict.txt");

  map<string, bool> m;
  for (int i{0}; i < 4617; ++i)
  {
    string x;
    dict >> x;
    m[x] = 1;
  }

  string serial;
  fin >> serial;

  bool some{false};
  vector<string> valids{valid_words(serial)};
  sort(valids.begin(), valids.end());
  for (auto ans : valids)
  {
    if (m[ans])
    {
      some = 1;
      fout << ans << "\n";
    }
  }
  if (!some) {
    fout << "NONE" << "\n";
  }
}
