#include <bits/stdc++.h>

using namespace std;

bool allEqual(int a[], int n) {
  for (int i{1}; i < n; ++i) {
    if (a[i] != a[0]) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  ++t;
  while (--t) {
    int n;
    cin >> n;
    int a[n];
    int tot{0};
    int min{INT_MAX};
    for (int i{0}; i < n; ++i) {
      cin >> a[i];
      if (a[i] < min) {
        min = a[i];
      }
    }
    for (int i{0}; i < n; ++i) {
      tot += a[i] - min;
    }
    cout << tot << endl;
  }
}
