/*
ID: saiansh1
LANG: C++
TASK: crypt1
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("crypt1.in", "r", stdin);
  freopen("crypt1.out", "w", stdout);

  int n;
  cin >> n;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  int tot{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      for (int k{0}; k < n; ++k) {
        for (int l{0}; l < n; ++l) {
          for (int m{0}; m < n; ++m) {
            int f{(a[i]*100+a[j]*10+a[k])*a[l]}, s{(a[i]*100+a[j]*10+a[k])*a[m]};
            if (f >= 1000) continue;
            if (find(a, a+n, f%10) == a+n || find(a, a+n, f/100) == a+n || find(a, a+n, f%100/10) == a+n) {
              continue;
            }
            if (s >= 1000) continue;
            if (find(a, a+n, s%10) == a+n || find(a, a+n, s/100) == a+n || find(a, a+n, s%100/10) == a+n) {
              continue;
            }
            f += s*10;
            if (find(a, a+n, f%10) == a+n || find(a, a+n, f/1000) == a+n || find(a,a+n,f%1000/100) == a+n || find(a,a+n,f%100/10) == a+n) continue;
            ++tot;
          }
        }
      }
    }
  }

  cout << tot << "\n";
}
