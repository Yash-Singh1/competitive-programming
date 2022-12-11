/*
ID: saiansh1
LANG: C++
TASK: frac1
*/

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("frac1.in", "r", stdin);
  freopen("frac1.out", "w", stdout);

  int n;
  cin >> n;

  vector<pair<double,pair<int,int>>> fracs((n+1)*(n+1));
  int fracc{0};
  for (int i{1}; i <= n; ++i) {
    for (int j{(i==1 ? 0 : 1)}; j <= i; ++j) {
      if (gcd(i, j) == 1) {
        fracs[fracc] = {(double)j/i, {j,i}};
        ++fracc;
      }
    }
  }
  sort(fracs.begin(), fracs.begin() + fracc);

  int k{0};
  for (auto &frac: fracs) {
    cout << frac.second.first << "/" << frac.second.second << "\n";
    ++k;
    if (k == fracc) break;
  }
}
