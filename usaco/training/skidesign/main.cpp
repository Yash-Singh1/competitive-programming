/*
ID: saiansh1
LANG: C++
TASK: skidesign
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("skidesign.in", "r", stdin);
  freopen("skidesign.out", "w", stdout);

  int n;
  cin >> n;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  int mcost{INT_MAX};
  for (int i{1}; i <= 100-17; ++i) {
    int cost{0};
    for (int j{0}; j < n; ++j) {
      if (a[j] < i) {
        cost += (i - a[j]) * (i - a[j]);
      } else if (a[j] > i+17) {
        cost += (a[j] - (i+17)) * (a[j] - (i+17));
      }
    }
    mcost = min(cost, mcost);
  }

  cout << mcost << "\n";
}
