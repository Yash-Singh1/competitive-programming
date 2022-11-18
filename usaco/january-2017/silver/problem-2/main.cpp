#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("hps.out");
  ifstream fin("hps.in");

  int n;
  fin >> n;
  int a[n];

  for (int i{0}; i < n; ++i) {
    char x;
    fin >> x;
    if (x == 'H') {
      a[i] = -1;
    } else if (x == 'P') {
      a[i] = 0;
    } else {
      a[i] = 1;
    }
  }

  int ans{-1};
  int p[n];
  int s[n];
  for (int i{-1}; i < 2; ++i) {
    for (int j{-1}; j < 2; ++j) {
      if (i != j) {
        for (int k{0}; k < n; ++k) {
          if (a[k] == i) {
            p[k] = 1;
          } else {
            p[k] = 0;
          }
          if (a[n - k - 1] == j) {
            s[k] = 1;
          } else {
            s[k] = 0;
          }
        }
        for (int k{1}; k < n; ++k) {
          p[k] += p[k - 1];
          s[k] += s[k - 1];
        }
        for (int k{0}; k < n - 1; ++k) {
          ans = max(ans, p[k] + s[n - k - 1]);
        }
      }
    }
  }

  fout << ans << "\n";
}
