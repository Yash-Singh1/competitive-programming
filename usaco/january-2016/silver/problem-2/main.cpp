/*
ID: saiansh1
LANG: C++
TASK: div7
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("div7.out");
  ifstream fin("div7.in");

  int n;
  fin >> n;
  map<int, int> m;
  int cur{0};
  m[0] = -1;
  int mx{-1};
  for (int i{0}; i < n; ++i) {
    int x;
    fin >> x;
    cur += x;
    cur %= 7;
    if (m.find(cur) == m.end()) {
      m[cur] = i;
    }
    mx = max(mx, i - m[cur]);
  }
  fout << mx << "\n";
}
