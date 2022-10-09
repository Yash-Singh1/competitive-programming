#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;

  int a[n];
  for (int i{0}; i < n; ++i) {
    a[i] = 0;
  }

  while (k--) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    ++a[x];
    if (y != n - 1) {
      --a[y + 1];
    }
  }

  for (int i{1}; i <n; ++i) {
    a[i] += a[i - 1];
  }

  sort(a, a + n);

  cout << a[n / 2];

  return 0;
}
