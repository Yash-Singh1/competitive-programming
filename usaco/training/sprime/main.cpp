/*
ID: saiansh1
LANG: C++
TASK: sprime
*/

#include <bits/stdc++.h>

using namespace std;

int primdigits[4] {2, 3, 5, 7};
int n;

void supprimes(int tot, int rn) {
  if (tot == n) {
    cout << rn << "\n";
  }
  int s;
  for (int i{1}; i <= 9; ++i) {
    if (i & 1) {
      s = rn * 10 + i;
      for (int j{2}; j <= sqrt(s); ++j) {
        if ((s % j) == 0) {
          goto alright;
        }
      }
      supprimes(tot + 1, s);
    }
    alright: continue;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("sprime.in", "r", stdin);
  freopen("sprime.out", "w", stdout);

  cin >> n;

  for (int i{0}; i < 4; ++i) {
    supprimes(1, primdigits[i]);
  }

  return 0;
}
