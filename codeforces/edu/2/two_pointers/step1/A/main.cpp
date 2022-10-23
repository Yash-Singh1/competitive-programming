// Given two sorted, arrays merge them into one sorted array in linear time

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  int b[m];
  for (int i{0}; i < m; ++i) {
    cin >> b[i];
  }

  int c[n + m];

  int ai{0};
  int bi{0};
  for (int i{0}; i < n + m; ++i) {
    if (ai >= n || (bi < m && b[bi] < a[ai])) {
      c[i] = b[bi];
      ++bi;
    } else {
      c[i] = a[ai];
      ++ai;
    }
    cout << c[i] << " ";
  }

  return 0;
}
