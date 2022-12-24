#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n, k;
  char x;
  cin >> t;

  while (t--) {
    cin >> n >> k;
    char pos[n];
    for (int i{0}; i < n; ++i) {
      pos[i] = '.';
    }
    int gtill{-1}, htill{-1};
    int placed{0};
    for (int i{0}; i < n; ++i) {
      cin >> x;
      if (x == 'G') {
        if (i > gtill) {
          gtill = i + 2*k;
          if (pos[min(i + k, n - 1)] != '.') {
            pos[min(i + k, n - 1) - 1] = 'G';
            --gtill;
          } else {
            pos[min(i + k, n - 1)] = 'G';
          }
          ++placed;
        }
      } else {
        if (i > htill) {
          htill = i + 2*k;
          if (pos[min(i + k, n - 1)] != '.') {
            pos[min(i + k, n - 1) - 1] = 'H';
            --htill;
          } else {
            pos[min(i + k, n - 1)] = 'H';
          }
          ++placed;
        }
      }
    }
    cout << placed << "\n";
    for (int i{0}; i < n; ++i) {
      cout << pos[i];
    }
    cout << "\n";
  }

  return 0;
}
