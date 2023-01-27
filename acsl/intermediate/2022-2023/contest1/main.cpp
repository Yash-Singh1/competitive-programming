#include <bits/stdc++.h>

using namespace std;

int countLargestDigit(int num, int base, int start) {
  int cur{0};
  string s{to_string(start)};
  int mul{1};
  for (int i{(int)s.size()-1}; i >= 0; --i) {
    cur += (s[i] - '0') * mul;
    mul *= base;
  }
  int largec{0};
  for (int i{0}; i < num; ++i) {
    int mfits{1};
    int cure{cur};
    // cout << cur << "\n";
    while (cur / mfits >= base) {
      mfits *= base;
    }
    while (mfits > 0) {
      // cout << "B" << cure << " " << mfits << "\n";
      largec += ((cure / mfits) == base-1);
      cure %= mfits;
      mfits /= base;
    };
    ++cur;
  }
  return largec;
}
