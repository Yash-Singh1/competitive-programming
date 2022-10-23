#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  for (int i{1}; i <n;++i) {
    a[i] += a[i - 1];
  }

  int low{0};
  int high{0};

  int mxbooks{-1};
  while (low < n) {
    while (high < n && a[high] - (low ? a[low - 1] : 0) <= t) {mxbooks=max(mxbooks,high-low);++high;}
    ++low;
  }

  mxbooks = max(mxbooks, high-low);

  cout << mxbooks+1;

  return 0;
}
