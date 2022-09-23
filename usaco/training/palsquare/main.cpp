/*
ID: saiansh1
LANG: C++
TASK: palsquare
*/

#include <bits/stdc++.h>

using namespace std;

char getChar(int x) {
  if (x >= 10) {
    char y = '7' + x;
    return y;
  }
  char y = '0' + x;
  return y;
}

int main()
{
  ofstream fout("palsquare.out");
  ifstream fin("palsquare.in");

  int b;
  fin >> b;

  for (int i{1}; i < 300; ++i) {
    int sq{i * i};
    int mi{i};
    int mxi{1};
    int pows{1};
    for (; mxi < i; mxi *= b) {
      ++pows;
    }

    string ans1{""};
    while (pows--) {
      ans1 += getChar(mi / mxi);
      if (ans1.size() == 1 && ans1[0] == '0') {
        ans1 = "";
      }
      mi %= mxi;
      mxi /= b;
    }

    mxi = 1;
    pows = 1;
    for (; mxi < sq; mxi *= b) {
      ++pows;
    }

    string ans = "";
    while (pows--) {
      ans += getChar(sq / mxi);
      if (ans.size() == 1 && ans[0] == '0') {
        ans = "";
      }
      sq %= mxi;
      mxi /= b;
    }

    string rev = ans;
    reverse(rev.begin(), rev.end());
    if (rev == ans) {
      fout << ans1 << " " << ans << "\n";
    }
  }
}
