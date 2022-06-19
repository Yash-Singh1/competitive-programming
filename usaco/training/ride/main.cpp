/*
ID: saiansh1
LANG: C++
TASK: ride
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("ride.out");
  ifstream fin("ride.in");
  string a, b;
  fin >> a >> b;
  int ap = 1;
  int bp = 1;
  for (long unsigned i{0}; i < a.size(); ++i) {
    int x{a[i] - 64};
    ap *= x;
  }
  for (long unsigned i{0}; i < b.size(); ++i) {
    int y{b[i] - 64};
    bp *= y;
  }
  if (ap % 47 == bp % 47) {
    fout << "GO" << "\n";
  } else {
    fout << "STAY" << "\n";
  }
}
