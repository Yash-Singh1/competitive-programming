#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);

  int k, n;
  cin >> k >> n;

  int a[k][n];

  for (int i{0}; i < k; ++i) {
    for (int j{0}; j < n; ++j) {
      int x;
      cin >> x;
      a[i][x - 1] = j;
    }
  }

  int freq{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (i != j) {
        bool consistent{1};
        for (int l{0}; l < k; ++l) {
          if (a[l][i] > a[l][j]) {
            consistent = 0;
          }
        }
        if (consistent) ++freq;
      }
    }
  }

  cout << freq;

  return 0;
}
