/*
ID: saiansh1
LANG: C++
TASK: beads
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("beads.out");
  ifstream fin("beads.in");

  int n;
  fin >> n;
  char ne[n];
  for (int i{0}; i < n; ++i) {
    fin >> ne[i];
  }
  int mxbeads{0};
  for (int i{0}; i < n; ++i) {
    bool stop{false};
    int beadshere{0};
    int initstoppoint{-1};
    char onebefore{ne[i - 1]};
    for (int j{i - 1}; j >= 0; --j) {
      if (onebefore == 'w' && ne[j] != 'w') {
        onebefore = ne[j];
      }
      if (ne[j] == onebefore || ne[j] == 'w') {
        ++beadshere;
      } else {
        stop = true;
        initstoppoint = j;
        break;
      }
    }
    int stoppoint{-1};
    if (!stop && i - 1 >= 0) {
      for (int j{n - 1}; j >= i; --j) {
        if (onebefore == 'w' && ne[j] != 'w') {
          onebefore = ne[j];
        }
        if (ne[j] == onebefore || ne[j] == 'w') {
          if (j == i) {
            stoppoint = i - 1;
          }
          ++beadshere;
        } else {
          stoppoint = j;
          break;
        }
      }
    }
    bool through{true};
    bool gotone{false};
    for (int j{i}; (stoppoint == -1 ? j < n : j <= stoppoint); ++j) {
      if (ne[j] == ne[i] || ne[j] == 'w') {
        ++beadshere;
      } else {
        through = false;
        break;
      }
      gotone = true;
    }
    if (gotone && through && stoppoint == -1 && initstoppoint != -1) {
      for (int j{0}; j <= initstoppoint; ++j) {
        if (ne[j] == ne[i] || ne[j] == 'w') {
          ++beadshere;
        } else {
          break;
        }
      }
    }
    //fout << i << " " << beadshere << endl;
    if (beadshere > mxbeads) {
      mxbeads = beadshere;
    }
  }
  fout << mxbeads << "\n";

  return 0;
}
