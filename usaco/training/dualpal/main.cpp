/*
ID: saiansh1
LANG: C++
TASK: dualpal
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

bool palBase(int num, int b) {
  int pow{0}, mxP{1};
  while (mxP <= num) {
    mxP *= b;
    ++pow;
  }
  mxP /= b;
  string ans;
  for (int i{0}; i < pow; ++i) {
    ans += getChar(num / mxP);
    if (ans.size() == 1 && ans[0] == '0') {
      ans = "";
    }
    num %= mxP;
    mxP /= b;
  }
  
  string rev = ans;
  reverse(rev.begin(), rev.end());

  if (ans == rev) {
    return true;
  }

  return false;
}

int main()
{
  ofstream fout("dualpal.out");
  ifstream fin("dualpal.in");

  int n, s;
  fin >> n >> s;
  ++s;

  for (int num{0}; num < n; ++s) {
    int did{0};
    for (int i{2}; (i <= 10 && did < 2); ++i) {
      if (palBase(s, i)) {
        ++did;
      }
    }
    if (did >= 2) {
      fout << s << "\n";
      ++num;
    }
  }
}
