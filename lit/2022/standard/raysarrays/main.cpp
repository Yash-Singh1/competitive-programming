// TLE, need better alg

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int a[n][n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  long long mdist{LONG_LONG_MAX};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      long long dist{0};
      bool die{false};
      for (int k{0}; k < n; ++k) {
        for (int l{0}; l < n; ++l) {
          dist += a[k][l] * abs((k - i) + (l - j));
          if (dist > mdist) {
            die = true;
            break;
          }
        }
        if (die) {
          break;
        }
      }
      if (die) {
        continue;
      }
      if (dist < mdist) {
        mdist = dist;
      }
    }
  }
  cout << mdist;
}
