/*
ID: saiansh1
LANG: C++
TASK: sort3
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("sort3.in", "r", stdin);
  freopen("sort3.out", "w", stdout);

  int n;
  cin >> n;

  int a[n];
  int b[n];
  int ones{0}, twos{0}, threes{0};
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    b[i] = a[i];
    if (a[i] == 1) {
      ++ones;
    } else if (a[i] == 2) {
      ++twos;
    } else {
      ++threes;
    }
  }

  int switches{0};
  for (int i{0}; i < ones; ++i) {
    if (a[i] != 1) {
      int f1{-1}, fl{0};
      for (int j{ones}; j < n; ++j) {
        if (f1 == -1 && a[j] == 1) f1 = j;
        if (a[j] == 1) {
          fl = j;
        }
      }
      if (fl > ones + twos && a[i] == 3) {
        a[fl] = 3;
        a[i] = 1;
      } else {
        a[f1] = a[i];
        a[i] = 1;
      }
      ++switches;
    }
  }

  for (int i{ones}; i < ones + twos; ++i) {
    if (a[i] != 2) {
      for (int j{ones + twos}; j < n; ++j) {
        if (a[j] == 2) {
          a[j] = 3;
          a[i] = 2;
          break;
        }
      }
      ++switches;
    }
  }

  cout << switches << "\n";
}
