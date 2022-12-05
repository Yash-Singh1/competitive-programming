/*
ID: saiansh1
LANG: C++
TASK: ariprog
*/

#include <bits/stdc++.h>

using namespace std;

set<int>s;
int n, m;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("ariprog.in", "r", stdin);
  freopen("ariprog.out", "w", stdout);

  cin >> n >> m;

  bool exists[2*62501];
  for (int i{0}; i <= 2*62500; ++i) exists[i] = 0;
  for (int i{0}; i <= m; ++i) {
    for (int j{i}; j <= m; ++j) {
      exists[i*i+j*j]=1;
    }
  }

  pair<int,int> a[10005];
  int tot{0};
  for (int i{0}; i < 2*62500; ++i) {
    if (!exists[i]) continue;
    for (int j{i+1}; j <= 2*62500; ++j) {
      if (i+(j-i)*(n-1) > 2*62500) {
        continue;
      }
      if (!exists[j]) continue;
      bool can{1};
      for (int k{2}; k < n; ++k) {
        if (!exists[i + ((j - i) * k)]) {
          can = 0;
          break;
        }
      }
      if (can) {
        a[tot] = {j-i, i};
        ++tot;
      }
    }
  }

  sort(a, a+tot);

  for (int i{0}; i < tot; ++i) {
    cout << a[i].second << " " << a[i].first << "\n";
  }

  if (tot == 0) {
    cout << "NONE\n";
  }
}
