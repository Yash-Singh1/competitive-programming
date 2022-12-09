/*
ID: saiansh1
LANG: C++
TASK: pprime
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pprime.in", "r", stdin);
  freopen("pprime.out", "w", stdout);

  int a, b;
  cin >> a >> b;

  for (int i{a}; i <= b; ++i) {
    if (i & 1) {
      int rev{0};
      int totd{0};
      int m{i};
      while (m > 0) {
        rev *= 10;
        totd += m%10;
        rev += m%10;
        m /= 10;
      }
      if ((totd % 3) == 0) continue;
      if (rev == i) {
        for (int j{2}; j <= sqrt(i); ++j) {
          if (i % j == 0) {
            goto alright;
          }
        }
        cout << i << "\n";
      }
      alright: continue;
    }
  }
}
