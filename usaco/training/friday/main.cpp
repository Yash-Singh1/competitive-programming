/*
ID: saiansh1
LANG: C++
TASK: friday
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("friday.out");
  ifstream fin("friday.in");
  int n;
  fin >> n;
  pair<int, int> t {1900, 1};
  int curDay{6}; // saturday
  int a[7]{0, 0, 0, 0, 0, 0, 1};
  while (true) {
    // fout << t.first << " " << t.second << endl;
    if (t.second == 4 || t.second == 6 || t.second == 9 || t.second == 11) {
      curDay += 30;
      curDay %= 7;
      ++t.second;
      ++a[curDay];
    } else if (t.second == 2) {
      ++t.second;
      if (t.first % 4 == 0 && (t.first % 100 != 0 || t.first % 400 == 0)) {
        curDay += 29;
      } else {
        curDay += 28;
      }
      curDay %= 7;
      ++a[curDay];
    } else if (t.second == 12) {
      curDay += 31;
      curDay %= 7;
      ++t.first;
      t.second = 1;
      if (t.first > (1900 + n - 1)) {
        break;
      }
      ++a[curDay];
    } else {
      curDay += 31;
      curDay %= 7;
      ++t.second;
      ++a[curDay];
    }
  }
  fout << a[6] << " ";
  for (int i{0}; i < 5; ++i) {
    fout << a[i] << " ";
  }
  fout << a[5] << "\n";
}
