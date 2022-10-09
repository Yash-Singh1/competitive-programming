/*
ID: saiansh1
LANG: C++
TASK: paintbarn
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("paintbarn.out");
  ifstream fin("paintbarn.in");

  int n, k;
  fin >> n >> k;

  int p[1001][1001];

  for (int i{0}; i < 1001; ++i) {
    for (int j{0}; j < 1001; ++j) {
      p[i][j] = 0;
    }
  }
  while (n--) {
    int x1, y1, x2, y2;
    fin >> x1 >> y1 >> x2 >> y2;
    ++p[x1][y1];
    --p[x2][y1];
    --p[x1][y2];
    ++p[x2][y2];
  }
  int ans{0};
  for (int i{0}; i < 1001; ++i) {
    for (int j{0}; j < 1001; ++j) {
      if (i != 0) {
        p[i][j] += p[i - 1][j];
      }
      if (j != 0) {
        p[i][j] += p[i][j - 1];
      }
      if (i != 0 && j != 0) {
        p[i][j] -= p[i - 1][j - 1];
      }
      if (p[i][j] == k) {
        ++ans;
      }
    }
  }
  fout << ans << "\n";
}
