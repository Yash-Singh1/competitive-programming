#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int a[n][n];
  for (int i{0}; i< n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  int rowley{0};
  int oddy, eveny;
  for (int i{0}; i < n; ++i) {
    oddy=0;
    eveny=0;
    for (int j{0}; j < n; ++j) {
      if (j&1) {
        oddy += a[i][j];
      } else {
        eveny += a[i][j];
      }
    }
    rowley += max(oddy, eveny);
  }

  int cowly{0};
  for (int i{0}; i < n; ++i) {
    oddy=0;
    eveny=0;
    for (int j{0}; j < n; ++j) {
      if (j&1) {
        oddy += a[j][i];
      } else {
        eveny += a[j][i];
      }
    }
    cowly += max(oddy, eveny);
  }

  cout << max(cowly, rowley) << "\n";

  return 0;
}
