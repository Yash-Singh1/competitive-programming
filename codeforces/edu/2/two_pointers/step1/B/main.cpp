#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int a[n], b[m];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }
  for (int i{0}; i < m; ++i) {
    cin >> b[i];
  }

  int low{-1};
  for (int i{0}; i < m; ++i) {
    while (low < n && a[low + 1] < b[i]) ++low;
    cout << min(low + 1, n) << " ";
  }

  return 0;
}
