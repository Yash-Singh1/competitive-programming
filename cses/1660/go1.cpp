#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  int low{0},high{0};

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  for (int i{1}; i < n; ++i) {
    a[i] += a[i - 1];
  }
  

  int sms{0};
  while (low < n) {
    while (high < n && a[high] - (low == 0 ? 0 : a[low - 1]) < x) {
      ++high;
    }
    if (a[high] - (low == 0 ? 0 : a[low - 1]) == x) {
      ++sms;
    }
    ++low;
  }

  cout << sms;

  return 0;
}
